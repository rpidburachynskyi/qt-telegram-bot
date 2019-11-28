#include "telegrambot.h"
#include "types/telegramreplykeyboardmarkup.h"
#include "types/telegramchatpermissions.h"
#include "types/telegraminlinekeyboardmarkup.h"
#include "types/telegraminputmedia.h"

#include <QJsonObject>
#include <QtNetwork>
#include <QJsonDocument>

TelegramBot::TelegramBot(const QString &token,
						 QNetworkAccessManager *manager,
						 QObject *parent) :
	QObject(parent),
	m_isPolled(false),
	m_token(token),
	m_mayUpdates(true)
{
	if(!manager)
		throw std::invalid_argument("Manager cannot be a nullptr");

	m_manager = manager;
	m_updateOffset = 0;
}

TelegramBot::TelegramBot(const QString &token,
						 QObject *parent) :
	TelegramBot(token, new QNetworkAccessManager, parent)
{ }

void TelegramBot::startPolling()
{
	m_isPolled = true;
	getUpdates();
}

void TelegramBot::stopPolling()
{
	m_isPolled = false;
}

void TelegramBot::setWebhook(const QString &url,
							 const int &maxConnection,
							 const QStringList &allowedUpdates)
{
	QTcpServer *server = new QTcpServer(this);

	server->listen(QHostAddress::Any, 3000);

	QJsonObject json;
	QJsonArray allowedUpds = QJsonArray::fromStringList(allowedUpdates);

	json["url"] = url;
	json["max_connections"] = maxConnection;
	if(allowedUpds.size() != 0)
		json["allowed_updates"] = allowedUpds;

	jsonSend("setWebhook", json);

	connect(server, &QTcpServer::newConnection, [this, server]()
	{
		QTcpSocket *socket = server->nextPendingConnection();

		connect(socket, &QTcpSocket::readyRead, [this, socket]()
		{
			auto data = socket->readAll();

			auto cleardata = data.right(data.size() - (data.indexOf("\r\n\r\n") + QString("\r\n\r\n").size()));
			QJsonDocument doc = QJsonDocument::fromJson(cleardata);
			socket->write("HTTP/1.0 200 OK\r\n\r\n");

			QJsonObject root = doc.object();

			emit onGetUpdates(root);
		});
	});
}

void TelegramBot::deleteWebhook()
{
	jsonSend("deleteWebhook");
}

void TelegramBot::getWebhookInfo()
{
	jsonSend("getWebhookInfo");
}

void TelegramBot::sendMessage(const QString &id,
							  const QString &text,
							  const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = id;
	json["text"] = text;
	if(replyMarkup)
		json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendMessage", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendMessage(const QString &id,
							  const QString &text,
							  const QString &m_parseMode,
							  const bool &disableWebPagePreview,
							  const bool &disableNofitication,
							  const int &replyToMessageId,
							  const TelegramReplyKeyboardMarkup *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = id;
	json["text"] = text;
	json["parse_mode"] = m_parseMode;
	json["disable_web_page_preview"] = disableWebPagePreview;
	json["disable_notification"] = disableNofitication;
	json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup)
		json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendMessage", json, TelegramRequest::SendMessages);
}

void TelegramBot::forwardMessage(const QString &chatId, const int &fromChatId, bool disableNotification, const int &messageId)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/forwardMessage");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["from_chat_id"] = fromChatId;
	object["disable_notification"] = disableNotification;
	object["message_id"] = messageId;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendPhoto(const QString &chatId, const QString &urlFile)
{
	QJsonObject object;
	object["chat_id"] = chatId;
	object["photo"] = urlFile;

	jsonSend("sendPhoto", object, TelegramRequest::GetUpdates);
}

void TelegramBot::sendPhoto(const QString &chatId)
{
	QJsonObject object;
	object["chat_id"] = chatId;
	multipartSend("sendPhoto", object);
}

void TelegramBot::sendVideo(const QString &chatId, const QString &urlFile)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendVideo");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["video"] = urlFile;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendAudio(const QString &chatId, const QString &urlFile)
{

	QJsonObject object;
	object["chat_id"] = chatId;
	object["audio"] = urlFile;

	jsonSend("sendAudio", object, TelegramRequest::SendMessages);
}

void TelegramBot::sendVideoNote(const QString &chatId, const QString &urlFile)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendVideoNote");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["video_note"] = urlFile;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendMediaGroup(const QString &chatId, const QStringList &urlFiles)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendMediaGroup");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonArray media;
	for(QString urlFile : urlFiles)
	{
		QJsonObject mediaItem;
		mediaItem["type"] = "photo";
		mediaItem["media"] = urlFile;
		media.append(mediaItem);
	}

	QJsonObject object;
	object["chat_id"] = chatId;
	object["media"] = media;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendDocument(const QString &chatId, const QString &urlFile)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendDocument");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["document"] = urlFile;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendAnimation(const QString &chatId, const QString &urlFile)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendAnimation");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["animation"] = urlFile;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendVoice(const QString &chatId, const QString &urlFile)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendVoice");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["voice"] = urlFile;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendChatAction(const QString &chatId, const TelegramBot::ChatAction &chatAction)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendChatAction");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	switch (chatAction)
	{
		case Typing: object["action"] = "typing"; break;
		case RecordAudio: object["action"] = "record_audio"; break;
		case UploadAudio: object["action"] = "upload_audio"; break;
		case UploadPhoto: object["action"] = "upload_photo"; break;
		case UploadVideo: object["action"] = "upload_video"; break;
		case FindLocation: object["action"] = "find_location"; break;
		case UploadVideoNote: object["action"] = "upload_video_note"; break;
		case UploadDocument: object["action"] = "upload_docucent"; break;
		case RecordVideoNote: object["action"] = "record_video_note"; break;
	}

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendLocation(const QString &chatId,
							   const double &latitude,
							   const double &longitude,
							   const int &livePeriod,
							   const bool &disableNotification,
							   const int &replyToMessageId)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendLocation");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["latitude"] = latitude;
	object["longitude"] = longitude;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendVenue(const QString &chatId,
							const double &latitude,
							const double &longitude,
							const QString &title,
							const QString &address,
							const bool &disableNotification)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendLocation");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["latitude"] = latitude;
	object["longitude"] = longitude;
	object["title"] = title;
	object["address"] = address;
	object["disable_notification"] = disableNotification;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendContact(const QString &chatId,
							  const QString &phoneNumber,
							  const QString &firstName,
							  const QString &lastName,
							  const QString &about,
							  const bool disableNotification,
							  const int &replyToMessageId)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendContact");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonObject object;
	object["chat_id"] = chatId;
	object["phone_number"] = phoneNumber;
	object["first_name"] = firstName;
	object["last_name"] = lastName;
	object["vcard"] = about;
	object["disable_notification"] = disableNotification;
	object["reply_to_message_id"] = replyToMessageId;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::sendPoll(const QString &chatId,
						   const QString &question,
						   const QStringList &optionsList,
						   const bool disableNotification,
						   const int &replyToMessageId)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/sendPoll");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QJsonArray options = QJsonArray::fromStringList(optionsList);

	QJsonObject object;
	object["chat_id"] = chatId;
	object["question"] = question;
	object["options"] = options;
	object["disable_notification"] = disableNotification;
	object["replyToMessageId"] = replyToMessageId;

	QJsonDocument doc (object);
	m_manager->post(request, doc.toJson());
}

void TelegramBot::getFile(const QString &fileId)
{
	QJsonObject object;
	object["file_id"] = fileId;

	jsonSend("getFile", object);
}

void TelegramBot::getMe()
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/getMe");
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	qDebug() << "GMS";

	m_manager->post(request, "");
}

void TelegramBot::getUpdates()
{
	if(!m_mayUpdates)
		return;
	QJsonObject root;
	root["offset"] = m_updateOffset;

	jsonSend("getUpdates", root, TelegramRequest::GetUpdates);
	m_mayUpdates = false;
}

void TelegramBot::kickChatMember(const QString &chatId,
								 const QString &userId,
								 const int &untilDate)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["user_id"] = userId;
	json["until_date"] = untilDate;

	jsonSend("kickChatMember", json);
}

void TelegramBot::unbanChatMember(const QString &chatId, const int &userId)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["user_id"] = userId;

	jsonSend("unbanChatMember", json);
}

void TelegramBot::restrictChatMember(const QString &chatId,
									 const int &userId,
									 const TelegramChatPermissions *permissions,
									 const int &untilDate)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["user_id"] = userId;
	json["permissions"] = permissions->toJson();
	json["until_date"] = untilDate;

	jsonSend("restrictChatMember", json);
}

void TelegramBot::promoteChatMember(const QString &chatId,
									const int &userId,
									const bool &canChangeInfo,
									const bool &canPostMessage,
									const bool &canEditMessage,
									const bool &canDeleteMessage,
									const bool &canInviteUsers,
									const bool &canRestrictMembers,
									const bool &canPinMessages,
									const bool &canPromoteMembers)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["user_id"] = userId;
	json["can_change_info"] = canChangeInfo;
	json["can_post_messages"] = canPostMessage;
	json["can_edit_messages"] = canEditMessage;
	json["can_delete_messages"] = canDeleteMessage;
	json["can_invite_users"] = canInviteUsers;
	json["can_restrict_members"] = canRestrictMembers;
	json["can_pin_messages"] = canPinMessages;
	json["can_promote_members"] = canPromoteMembers;

	jsonSend("promoteChatMember", json);
}

void TelegramBot::setChatPermissions(const QString &chatId,
									 const TelegramChatPermissions &permissions)
{
	QJsonObject json;
	json["chat_id"] = chatId;
//	json["permissions"] = permissions.toJson();

	jsonSend("setChatPermissions", json);
}

void TelegramBot::exportChatInviteLink(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("exportChatInviteLink", json);
}

void TelegramBot::deleteChatPhoto(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("deleteChatPhoto", json);
}

void TelegramBot::setChatTitle(const QString &chatId,
							   const QString &title)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["title"] = title;

	jsonSend("setChatTitle", json);
}

void TelegramBot::setChatDescription(const QString &chatId,
									 const QString &description)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["description"] = description;

	jsonSend("setChatDescription", json);
}

void TelegramBot::pinChatMessage(const QString &chatId,
								 const QString &messageId,
								 const bool &disableNotification)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["message_id"] = messageId;
	json["disable_notification"] = disableNotification;

	jsonSend("pinChatMessage", json);
}

void TelegramBot::unpinChatMessage(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("unpinChatMessage", json);
}

void TelegramBot::leaveChat(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("leaveChat", json);
}

void TelegramBot::getChat(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("getChat", json, TelegramRequest::GetChat);
}

void TelegramBot::getChatAdministators(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("getChatAdministators", json, TelegramRequest::GetChatAdministators);
}

void TelegramBot::getChatMemberCount(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("getChatMemberCount", json, TelegramRequest::GetChatAdministators);
}

void TelegramBot::getChatMember(const QString &chatId, const QString &userId)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["user_id"] = userId;

	jsonSend("getChatMember", json, TelegramRequest::GetChatAdministators);
}

void TelegramBot::setChatStickerSet(const QString &chatId, const QString &stickerSetName)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["sticker_set_name"] = stickerSetName;

	jsonSend("setChatStickerSet", json, TelegramRequest::GetChatAdministators);
}

void TelegramBot::deleteChatStickerSet(const QString &chatId)
{
	QJsonObject json;
	json["chat_id"] = chatId;

	jsonSend("deleteChatStickerSet", json, TelegramRequest::GetChatAdministators);
}

void TelegramBot::editMessageText(const QString &chatId,
								  const int &messageId,
								  const QString &newText,
								  const QString &parseMode,
								  const bool &disableWebPagePreview)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["message_id"] = messageId;
	json["text"] = newText;
	json["parse_mode"] = parseMode;
	json["disable_web_page_preview"] = disableWebPagePreview;


	jsonSend("editMessageText", json, TelegramRequest::GetChat);
}

void TelegramBot::editMessageCaption(const QString &chatId,
									 const int &messageId,
									 const QString &newCaption,
									 const QString &parseMode,
									 const bool &disableWebPagePreview)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["message_id"] = messageId;
	json["caption"] = newCaption;
	json["parse_mode"] = parseMode;
	json["disable_web_page_preview"] = disableWebPagePreview;


	jsonSend("editMessageCaption", json, TelegramRequest::GetChat);
}

void TelegramBot::editMessageMedia(const QString &chatId,
								   const QString &messageId,
								   const TelegramInputMedia &inputMedia)
{
	QJsonObject json;

	json["chat_id"] = chatId;
	json["message_id"] = messageId;
	json["media"] = inputMedia.toJson();

	jsonSend("editMessageMedia", json);
}

void TelegramBot::deleteMessage(const QString &chatId, const QString &messageId)
{
	QJsonObject json;

	json["chat_id"] = chatId;
	json["message_id"] = messageId;

	jsonSend("deleteMessage", json);
}

void TelegramBot::onGetUpdates(const QJsonObject &resultObject)
{
	qDebug() << resultObject;
	TelegramResult *result = TelegramResults::resultFromJSOM(resultObject);
	TelegramUpdate *update = static_cast<TelegramUpdate *>(result);
	if(update)
	{
		if(update->message())
		{
			emit onMessage(update->message());
		}
	}

	delete result;
}

void TelegramBot::onGetUpdates(const QJsonValueRef &resultObject)
{
	if(resultObject.isArray())
	{
		TelegramResults results(resultObject.toArray());

		for(TelegramResult *result : results.results())
		{
			TelegramUpdate *update = static_cast<TelegramUpdate *>(result);
			if(update)
			{
				if(update->message())
				{
					emit onMessage(update->message());
				}
			}
			m_updateOffset = update->updateId().toInt() + 1;
		}
	}else
	{
		onGetUpdates(resultObject.toObject());
	}
}

void TelegramBot::onGetUpdates(TelegramRequest *telegramRequest)
{
	auto data = telegramRequest->reply()->readAll();
	QJsonDocument doc = QJsonDocument::fromJson(data);
	QJsonObject root = doc.object();
	qDebug() << doc;

	auto resultObject = root["result"];

	onGetUpdates(resultObject);

	m_mayUpdates = true;
	telegramRequest->reply()->deleteLater();
	if(m_isPolled)
		getUpdates();
}

void TelegramBot::onGetChat(TelegramRequest *telegramRequest)
{
	QJsonDocument doc = QJsonDocument::fromJson(telegramRequest->reply()->readAll());
	QJsonObject root = doc.object();
}

void TelegramBot::onGetChatAdministators(TelegramRequest *telegramRequest)
{

}

void TelegramBot::onGetChatMemberCount(TelegramRequest *telegramRequest)
{

}

void TelegramBot::onGetChatMember(TelegramRequest *telegramRequest)
{

}

void TelegramBot::onTelegramRequestReply(TelegramRequest *telegramRequest)
{
	TelegramRequest::RequestType rtype = telegramRequest->requestType();

	QJsonDocument doc = QJsonDocument::fromJson(telegramRequest->reply()->readAll());
	QJsonObject json = doc.object();

	switch (rtype)
	{
		case TelegramRequest::SendMessages:
		{
			TelegramMessage message(json["result"].toObject());
			onBotMessage(&message);
			break;
		}

		default:
			break;
	}
}

void TelegramBot::jsonSend(const QString &title,
						   const QJsonObject &json,
						   TelegramRequest::RequestType requestType)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/" + title);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");
	QJsonDocument doc (json);
	auto reply = m_manager->post(request, doc.toJson());

	TelegramRequest *telegramRequest = new TelegramRequest(reply, requestType, this);
}

void TelegramBot::multipartSend(const QString &title,
								QJsonObject &json)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/" + title);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");

	QHttpMultiPart *multi = new QHttpMultiPart(QHttpMultiPart::FormDataType);
	QHttpPart imagePart;
	imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
	imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"tyson.jpg\""));

	QFile *file = new QFile("D:\\Downloads\\111.jpg", multi);
	file->open(QIODevice::ReadOnly);

	QJsonObject inputF;
	inputF["id"] = "123asjk78a3s121123235gfghfvfdfgfgh545434fgjyasesd12rqis3ry458d7";
	inputF["parts"] = 1024;
	inputF["name"] = "tyson.jpg";

	json["photo"] = inputF;

	QHttpPart metaPart;
	metaPart.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
	metaPart.setBody(QJsonDocument(json).toJson());
	multi->append(metaPart);


	imagePart.setBodyDevice(file);

	multi->append(imagePart);


	auto reply = m_manager->post(request, multi);

	TelegramRequest *trequest = new TelegramRequest(reply, TelegramRequest::GetUpdates, this);

	multi->setParent(reply);
}

