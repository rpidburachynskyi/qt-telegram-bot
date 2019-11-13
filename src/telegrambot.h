#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "telegramrequest.h"
#include "types/telegrammessage.h"
#include "types/telegramresults.h"
#include "types/telegramresult.h"
#include "types/telegramupdate.h"
#include "types/itelegrammessagekeyboard.h"

class TelegramReplyKeyboardMarkup;
class TelegramInlineKeyboardMarkup;
class TelegramChatPermissions;
class TelegramInputMedia;

class TelegramBot : public QObject
{
	Q_OBJECT

	friend class TelegramRequest;
public:
	enum ChatAction
	{
		Typing,
		UploadPhoto,
		UploadVideo,
		RecordAudio,
		UploadAudio,
		UploadDocument,
		FindLocation,
		RecordVideoNote,
		UploadVideoNote
	};

	TelegramBot(const QString &token);

	void startPolling();
	void stopPolling();

	void setWebhook(const QString &url,
					const int &maxConnection = 40,
					const QStringList &allowedUpdates = {});
	void deleteWebhook();
	void getWebhookInfo();

	void sendMessage(const QString &id,
					 const QString &text,
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);

	void sendMessage(const QString &id,
					 const QString &text,
					 const QString &m_parseMode,
					 const bool &disableWebPagePreview = false,
					 const bool &disableNofitication = false,
					 const int &replyToMessageId = -1,
					 const TelegramReplyKeyboardMarkup *replyMarkup = nullptr);

	void forwardMessage(const QString &chatId,
						const int &fromChatId,
						bool disableNotification,
						const int& messageId);
	void sendPhoto(const QString &chatId, const QString &urlFile);
	void sendPhoto(const QString &chatId); // FIX IT
	void sendVideo(const QString &chatId, const QString &urlFile);
	void sendAudio(const QString &chatId, const QString &urlFile);

	void sendVideoNote(const QString &chatId, const QString &urlFile);

	void sendMediaGroup(const QString &chatId, const QStringList &urlFiles);

	void sendDocument(const QString &chatId, const QString &urlFile);
	void sendAnimation(const QString &chatId, const QString &urlFile);
	void sendVoice(const QString &chatId, const QString &urlFile);

	void sendChatAction(const QString &chatId, const ChatAction &chatAction);
	void sendLocation(const QString &chatId,
					  const double &latitude,
					  const double &longitude,
					  const int &livePeriod = -1,
					  const bool &disableNotification = false,
					  const int &replyToMessageId = -1);
	void sendVenue(const QString& chatId,
				   const double &latitude,
				   const double &longitude,
				   const QString &title,
				   const QString &address,
				   const bool &disableNotification = false);
	void sendContact(const QString &chatId,
					 const QString &phoneNumber,
					 const QString &firstName,
					 const QString &lastName,
					 const QString &about = "",
					 const bool disableNotification = false,
					 const int &replyToMessageId = -1);
	void sendPoll(const QString& chatId,
				  const QString &question,
				  const QStringList &optionsList,
				  const bool disableNotification = false,
				  const int &replyToMessageId = -1);

	void getFile(const QString &fileId);

	void getMe();
	void getUpdates();

	void kickChatMember(const QString &chatId,
						const QString &userId,
						const int &untilDate = 0);

	void unbanChatMember(const QString &chatId,
						const int &userId);

	void restrictChatMember(const QString &chatId,
							const int &userId,
							const TelegramChatPermissions *permissions,
							const int &untilDate = 0);

	void promoteChatMember(const QString &chatId,
						   const int &userId,
						   const bool &canChangeInfo,
						   const bool &canPostMessage,
						   const bool &canEditMessage,
						   const bool &canDeleteMessage,
						   const bool &canInviteUsers,
						   const bool &canRestrictMembers,
						   const bool &canPinMessages,
						   const bool &canPromoteMembers);

	void setChatPermissions(const QString &chatId,
							const TelegramChatPermissions &permissions);

	void exportChatInviteLink(const QString &chatId);

	void setChatPhoto(); // FIXIT
	void deleteChatPhoto(const QString &chatId);
	void setChatTitle(const QString &chatId, const QString &title);
	void setChatDescription(const QString &chatId, const QString &description);

	void pinChatMessage(const QString &chatId, const QString &messageId, const bool &disableNotification);
	void unpinChatMessage(const QString &chatId);

	void leaveChat(const QString &chatId);
	void getChat(const QString &chatId);
	void getChatAdministators(const QString &chatId);
	void getChatMemberCount(const QString &chatId);
	void getChatMember(const QString &chatId, const QString &userId);

	void setChatStickerSet(const QString &chatId, const QString &stickerSetName);
	void deleteChatStickerSet(const QString &chatId);

	void editMessageText(const QString &chatId,
						 const int &messageId,
						 const QString &newText,
						 const QString &parseMode = "",
						 const bool &disableWebPagePreview = false);

	void editMessageCaption(const QString &chatId,
						 const int &messageId,
						 const QString &newCaption,
						 const QString &parseMode = "",
						 const bool &disableWebPagePreview = false);

	void editMessageMedia(const QString &chatId,
						  const QString &messageId,
						  const TelegramInputMedia &inputMedia);

signals:
	void onMessage(const TelegramMessage *message);
	void onExportChatInviteLink(const QString &joinLink);

	void onBotMessage(const TelegramMessage *message);

private slots:
	void onGetUpdates(const QJsonObject &resultObject);
	void onGetUpdates(const QJsonValueRef &resultObject);
	void onGetUpdates(TelegramRequest *telegramRequest);
	void onGetChat(TelegramRequest *telegramRequest);
	void onGetChatAdministators(TelegramRequest *telegramRequest);
	void onGetChatMemberCount(TelegramRequest *telegramRequest);
	void onGetChatMember(TelegramRequest *telegramRequest);

	void onTelegramRequestReply(TelegramRequest *telegramRequest);

private:
	bool m_isPolled;
	QString m_token;
	int m_updateOffset;
	QNetworkAccessManager m_manager;

	bool m_mayUpdates;

	void jsonSend(const QString &title,
				  const QJsonObject &json = QJsonObject(),
				  TelegramRequest::RequestType requestType = TelegramRequest::Unknown);

	void multipartSend(const QString &title,
				  QJsonObject &json); // FIX IT
};

#endif // TELEGRAMBOT_H
