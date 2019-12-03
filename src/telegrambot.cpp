#include "telegrambot.h"
#include "types/telegramreplykeyboardmarkup.h"
#include "types/telegramchatpermissions.h"
#include "types/telegraminlinekeyboardmarkup.h"
#include "types/telegraminputmedia.h"
#include "telegramrequestdownload.h"

#include <QJsonObject>
#include <QtNetwork>
#include <QJsonDocument>

TelegramBot::TelegramBot(const QString &token,
						 QNetworkAccessManager *manager,
						 QObject *parent) :
	QObject(parent),
	m_isPolled(false),
	m_token(token),
	m_listenServer(nullptr),
	m_mayUpdates(true)
{
	if(!manager)
		throw std::invalid_argument("Manager cannot be a nullptr");

	m_manager = manager;
	m_updateOffset = 0;

	connect(manager, &QNetworkAccessManager::sslErrors, [](QNetworkReply *, const QList<QSslError> &errors)
	{
		qDebug() << "SSL ERRORS SIZE" << errors.size();
	});
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

void TelegramBot::setWebhook(QTcpServer *server,
							 const QString &url,
							 const int &maxConnection,
							 const QStringList &allowedUpdates)
{
	m_listenServer = server;

	QJsonObject json;
	QJsonArray allowedUpds = QJsonArray::fromStringList(allowedUpdates);

	json["url"] = url;
	json["max_connections"] = maxConnection;
	if(allowedUpds.size() != 0)
		json["allowed_updates"] = allowedUpds;

	jsonSend("setWebhook", json);

	if(!m_listenServer->isListening())
	{
		quint16 port;
		if(m_listenServer->serverPort() == 0)
			port = 3000;
		else
			port = server->serverPort();
		m_listenServer->listen(QHostAddress::Any, port);
	}


	connect(m_listenServer, &QTcpServer::newConnection, [this]()
	{
		QTcpSocket *socket = m_listenServer->nextPendingConnection();

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
	QJsonObject json;
	json["chat_id"] = chatId;
	json["from_chat_id"] = fromChatId;
	json["disable_notification"] = disableNotification;
	json["message_id"] = messageId;

	jsonSend("forwardMessage", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendAudio(const QString &chatId,
							const QString &urlFileOrFileId,
							const QString &caption,
							const QString &parseMode,
							const int duration,
							const QString &performer,
							const QString &title,
							const QString &thumb,
							const bool &disableNotification,
							const QString replyToMessageId,
							const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["audio"] = urlFileOrFileId;
	json["disable_notification"] = disableNotification;
	if(!caption.isEmpty()) json["caption"] = caption;
	if(!parseMode.isEmpty()) json["parse_mode"] = parseMode;
	if(duration > -1) json["duration"] = duration;
	if(!performer.isEmpty()) json["parformer"] = performer;
	if(!title.isEmpty()) json["title"] = title;
	if(!thumb.isEmpty()) json["thumb"] = thumb;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendAudio", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendVideoNote(const QString &chatId,
								const QString &urlFileOrFileId,
								const int &duration,
								const int &length,
								const QString &thumb,
								const bool &disableNotification,
								const QString &replyToMessageId,
								const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["video_note"] = urlFileOrFileId;
	json["disable_notification"] = disableNotification;
	if(duration > -1) json["duration"] = duration;
	if(length > -1) json["length"] = length;
	if(!thumb.isEmpty()) json["thumb"] = thumb;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendVideoNote", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendMediaGroup(const QString &chatId, const QStringList &urlFilesOrFileIds, const bool &disableNotification, const QString &replyToMessageId)
{
	QJsonArray media;
	for(QString urlFile : urlFilesOrFileIds)
	{
		QJsonObject mediaItem;
		mediaItem["type"] = "photo";
		mediaItem["media"] = urlFile;
		media.append(mediaItem);
	}

	QJsonObject json;
	json["chat_id"] = chatId;
	json["media"] = media;
	json["disable_notification"] = disableNotification;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;

	jsonSend("sendMediaGroup", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendDocument(const QString &chatId,
							   const QString &urlFileOrFileId,
							   const QString &thumb,
							   const QString &caption,
							   const QString &parseMode,
							   const bool &disableNotification,
							   const QString &replyToMessageId,
							   const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["document"] = urlFileOrFileId;
	json["disable_notification"] = disableNotification;

	if(!thumb.isEmpty()) json["thumb"] = thumb;
	if(!caption.isEmpty()) json["caption"] = caption;
	if(!parseMode.isEmpty()) json["parse_mode"] = parseMode;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendVideo", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendAnimation(const QString &chatId,
								const QString &urlFileOrFileId,
								const QString &thumb,
								const QString &caption,
								const QString &parseMode,
								const bool &disableNotification,
								const QString &replyToMessageId,
								const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["animation"] = urlFileOrFileId;
	json["disable_notification"] = disableNotification;

	if(!thumb.isEmpty()) json["thumb"] = thumb;
	if(!caption.isEmpty()) json["caption"] = caption;
	if(!parseMode.isEmpty()) json["parse_mode"] = parseMode;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendAnimation", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendVoice(const QString &chatId,
							const QString &urlFileOrFileId,
							const QString &caption,
							const QString &parseMode,
							const int &duration,
							const bool &disableNotification,
							const QString &replyToMessageId,
							const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["voice"] = urlFileOrFileId;
	json["disable_notification"] = disableNotification;

	if(!caption.isEmpty()) json["caption"] = caption;
	if(!parseMode.isEmpty()) json["parse_mode"] = parseMode;
	if(duration > -1) json["duration"] = duration;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendAnimation", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendChatAction(const QString &chatId, const QString &chatAction)
{
	ChatAction c = TelegramBot::Unknown;

	QString s = chatAction;

	if(s == "typing") c = Typing;
	else if(s == "record_audio") c = RecordAudio;
	else if(s == "upload_audio") c = UploadAudio;
	else if(s == "upload_photo") c = UploadPhoto;
	else if(s == "upload_video") c = UploadVideo;
	else if(s == "find_location") c = FindLocation;
	else if(s == "upload_video_note") c = UploadVideoNote;
	else if(s == "upload_document") c = UploadDocument;
	else if(s == "record_video_note") c = RecordVideoNote;

	if(c == Unknown)
		std::invalid_argument("Unknown chat action");
	sendChatAction(chatId, c);
}

void TelegramBot::sendChatAction(const QString &chatId,
								 const TelegramBot::ChatAction &chatAction)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	switch (chatAction)
	{
		case Typing: json["action"] = "typing"; break;
		case RecordAudio: json["action"] = "record_audio"; break;
		case UploadAudio: json["action"] = "upload_audio"; break;
		case UploadPhoto: json["action"] = "upload_photo"; break;
		case UploadVideo: json["action"] = "upload_video"; break;
		case FindLocation: json["action"] = "find_location"; break;
		case UploadVideoNote: json["action"] = "upload_video_note"; break;
		case UploadDocument: json["action"] = "upload_document"; break;
		case RecordVideoNote: json["action"] = "record_video_note"; break;
		default: throw std::invalid_argument("Unknown chat action");
	}

	jsonSend("sendChatAction", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendLocation(const QString &chatId,
							   const double &latitude,
							   const double &longitude,
							   const int &livePeriod,
							   const bool &disableNotification,
							   const QString &replyToMessageId,
							   const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["latitude"] = latitude;
	json["longitude"] = longitude;
	json["disable_notification"] = disableNotification;

	if(livePeriod > -1) json["live_period"] = livePeriod;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendLocation", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendVenue(const QString &chatId,
							const double &latitude,
							const double &longitude,
							const QString &title,
							const QString &address,
							const bool &disableNotification,
							const QString &replyToMessageId,
							const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["latitude"] = latitude;
	json["longitude"] = longitude;
	json["disable_notification"] = disableNotification;

	if(!title.isEmpty()) json["title"] = title;
	if(!address.isEmpty()) json["address"] = address;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendVenue", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendContact(const QString &chatId,
							  const QString &phoneNumber,
							  const QString &firstName,
							  const QString &lastName,
							  const QString &about,
							  const bool disableNotification,
							  const QString &replyToMessageId,
							  const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["phone_number"] = phoneNumber;
	json["first_name"] = firstName;
	json["disable_notification"] = disableNotification;

	if(!lastName.isEmpty()) json["last_name"] = lastName;
	if(!about.isEmpty()) json["vcard"] = about;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;

	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();


	jsonSend("sendContact", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendPoll(const QString &chatId,
						   const QString &question,
						   const QStringList &optionsList,
						   const bool disableNotification,
						   const QString &replyToMessageId,
						   const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonArray options = QJsonArray::fromStringList(optionsList);

	QJsonObject json;
	json["chat_id"] = chatId;
	json["question"] = question;
	json["options"] = options;
	json["disable_notification"] = disableNotification;

	if(!replyToMessageId.isEmpty()) json["replyToMessageId"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendPoll", json, TelegramRequest::SendMessages);
}

void TelegramBot::sendSticker(const QString &chatId,
							  const QString &url,
							  const bool &disableNotification,
							  const QString &replyToMessageId,
							  const iTelegramMessageKeyboard *replyMarkup)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	json["sticker"] = url;
	json["disable_notification"] = disableNotification;

	if(!replyToMessageId.isEmpty()) json["replyToMessageId"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	jsonSend("sendSticker", json, TelegramRequest::SendMessages);
}

void TelegramBot::getFile(const QString &fileId)
{
	QJsonObject json;
	json["file_id"] = fileId;

	jsonSend("getFile", json, TelegramRequest::GetFile);
}

void TelegramBot::getStickerSet(const QString &name)
{
	QJsonObject json;

	json["name"] = name;

	jsonSend("getStickerSet", json, TelegramRequest::GetStickerSet);
}

void TelegramBot::getMe()
{
	jsonSend("getMe", QJsonObject(), TelegramRequest::GetMe);
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
	json["permissions"] = permissions.toJson();

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

void TelegramBot::downloadFile(const QString &filePath)
{
	QUrl url("https://api.telegram.org/file/bot" + m_token + "/" + filePath);

	qDebug() << "START";
	QNetworkReply* reply = m_manager->get(QNetworkRequest(url));

	TelegramRequestDownload *downloadRequest = new TelegramRequestDownload(reply);

	connect(downloadRequest, &TelegramRequestDownload::downloaded, [this](const QString &fileName,
			const QByteArray &data)
	{
		emit fileDownloaded(fileName, data);
	});
}

QTcpServer* TelegramBot::createListenServer(const quint16 port)
{
	QTcpServer *server = new QTcpServer;

	server->listen(QHostAddress::Any, port);

	return server;
}

void TelegramBot::deleteListenServer()
{
	if(m_listenServer)
	{
		m_listenServer->deleteLater();
		m_listenServer = nullptr;
	}
}

void TelegramBot::onGetUpdates(const QJsonObject &resultObject)
{
	TelegramResult *result = TelegramResults::resultFromJSOM(resultObject);
	TelegramUpdate *update = static_cast<TelegramUpdate *>(result);
	if(update)
	{
		if(update->message())
		{
			emit messaged(update->message());
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
					emit messaged(update->message());
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

	if(!root["ok"].toBool())
		return emit errored(doc.toJson());

	auto resultObject = root["result"];

	onGetUpdates(resultObject);

	m_mayUpdates = true;
	telegramRequest->reply()->deleteLater();
	if(m_isPolled)
		getUpdates();
}

void TelegramBot::onTelegramRequestReply(TelegramRequest *telegramRequest)
{
	TelegramRequest::RequestType rtype = telegramRequest->requestType();

	QJsonDocument doc = QJsonDocument::fromJson(telegramRequest->reply()->readAll());
	QJsonObject json = doc.object();
	QJsonObject result = json["result"].toObject();
	switch (rtype)
	{
		case TelegramRequest::SendMessages:
		{
			TelegramMessage message(result);

			emit botMessaged(&message);
			break;
		}
		case TelegramRequest::GetChat:
		{
			TelegramChat chat(result);

			emit getChatReady(chat);
			break;
		}
		case TelegramRequest::GetStickerSet:
		{
			QJsonDocument doc = QJsonDocument::fromJson(telegramRequest->reply()->readAll());
			QJsonObject json = doc.object()["result"].toObject();

			TelegramStickerSet stickerSet(json);

			emit getStickerSetReady(stickerSet);
			break;
		}
		case TelegramRequest::GetFile:
		{
			TelegramFile file(result);

			getFileReady(file);
			break;
		}
		default:
			break;
	}
}

void TelegramBot::sendPhoto(const QString &id,
								   const QString &f,
								   const QString &c,
								   const QString &p,
								   const bool &d,
								   const QString &r,
								   const iTelegramMessageKeyboard *rm,
								   const bool &j)
{
	QJsonObject json;
	json["chat_id"] = id;
	if(j)
		json["photo"] = f;
	json["disable_notification"] = d;

	if(!c.isEmpty()) json["caption"] = c;
	if(!p.isEmpty()) json["parse_mode"] = p;
	if(!r.isEmpty()) json["reply_to_message_id"] = r;
	if(rm) json["reply_markup"] = rm->toJson();

	if(j) jsonSend("sendPhoto", json, TelegramRequest::SendMessages);
	else multipartSend("sendPhoto", json, packPhoto(f));
}

void TelegramBot::sendVideo(const QString &chatId,
							const QString &f,
							const int &duration,
							const int &width,
							const int &height,
							const QString &thumb,
							const QString &caption,
							const QString &parseMode,
							const bool &supportsStreaming,
							const bool &disableNotification,
							const QString &replyToMessageId,
							const iTelegramMessageKeyboard *replyMarkup,
							const bool &j)
{
	QJsonObject json;
	json["chat_id"] = chatId;
	if(j)
		json["video"] = f;
	json["supports_streaming"] = supportsStreaming;
	json["disable_notification"] = disableNotification;

	if(duration > -1) json["duration"] = duration;
	if(width > -1) json["width"] = width;
	if(height > -1) json["height"] = height;
	if(!thumb.isEmpty()) json["thumb"] = thumb;
	if(!caption.isEmpty()) json["caption"] = caption;
	if(!parseMode.isEmpty()) json["parse_mode"] = parseMode;
	if(!replyToMessageId.isEmpty()) json["reply_to_message_id"] = replyToMessageId;
	if(replyMarkup) json["reply_markup"] = replyMarkup->toJson();

	if(j) jsonSend("sendVideo", json, TelegramRequest::SendMessages);
	else multipartSend("sendVideo", json, packVideo(f));
}

void TelegramBot::jsonSend(const QString &title,
						   const QJsonObject &json,
						   const TelegramRequest::RequestType &requestType)
{
	QUrl url("https://api.telegram.org/bot" + m_token + "/" + title);
	QNetworkRequest request(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader,
		"application/json");
	QJsonDocument doc (json);
	QNetworkReply *reply = m_manager->post(request, doc.toJson());

	TelegramRequest *telegramRequest = new TelegramRequest(reply, requestType, this);
}

void TelegramBot::multipartSend(const QString &title,
								const QJsonObject &json,
								const QHttpPart &part)
{
	QUrlQuery query;
	QUrl url("https://api.telegram.org/bot" + m_token + "/" + title);

	QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::ContentType::FormDataType);
	multiPart->append(part);

	for(auto key : json.keys())
		query.addQueryItem(key, json[key].toString());

	url.setQuery(query);

	QNetworkRequest request(url);
	QNetworkReply *reply = m_manager->post(request, multiPart);

	TelegramRequest *trequest = new TelegramRequest(reply, TelegramRequest::SendMessages, this);

	multiPart->setParent(reply);

	connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), [](QNetworkReply::NetworkError er){
		qDebug() << "ERROR:" << er;
	});
}

QHttpPart TelegramBot::packFile(const QString &path,
								const QString &fieldname)
{
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	QByteArray data = file.readAll();
	QFileInfo info(file);

	QString dispositionHeader = QString("form-data; name=\"%1\"; filename=\"%2\"")
			.arg(fieldname)
			.arg(info.fileName());
	QHttpPart part;

	QString typeHeader = "video/mp4";

	if(info.completeSuffix() == "png") typeHeader = "image/png";
	else if(info.completeSuffix() == "jpg" || info.completeSuffix() == "jpeg") typeHeader = "image/jpg";
	// FIXIT

	part.setHeader(QNetworkRequest::ContentDispositionHeader, dispositionHeader);
	part.setHeader(QNetworkRequest::ContentTypeHeader, typeHeader);
	part.setBody(data);

	return part;
}
