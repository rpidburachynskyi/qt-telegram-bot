#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "telegramrequest.h"
#include "types/itelegrammessagekeyboard.h"
#include "types/telegrammessage.h"
#include "types/telegramresults.h"
#include "types/telegramresult.h"
#include "types/telegramupdate.h"
#include "types/telegramchat.h"
#include "types/telegramfile.h"
#include "types/telegrammessage.h"
#include "types/telegramchat.h"
#include "types/telegramaudio.h"
#include "types/telegramdocument.h"
#include "types/telegramvideo.h"
#include "types/telegramcontact.h"
#include "types/telegrammessageentity.h"
#include "types/telegraminlinekeyboardmarkup.h"
#include "types/telegramuser.h"
#include "types/telegramforcereply.h"
#include "types/telegramreplykeyboardmarkup.h"
#include "types/telegraminputmediaaudio.h"
#include "types/telegraminputmediavideo.h"
#include "types/telegraminputmediaanimation.h"
#include "types/telegramreplykeyboardremove.h"
#include "types/telegramchatphoto.h"
#include "types/telegramphotosize.h"
#include "stickers/telegramstickerset.h"

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
		Unknown,
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

	TelegramBot(const QString &token, QObject *parent = nullptr);
	TelegramBot(const QString &token, QNetworkAccessManager *manager, QObject *parent = nullptr);

	void startPolling();
	void stopPolling();

	void setWebhook(QTcpServer *server,
					const QString &url,
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
	inline void sendPhotoById(const QString &chatId,
							  const QString &fileId,
							  const QString &caption = "",
							  const QString &parseMode = "",
							  const bool &disableNotification = false,
							  const QString &replyToMessageId = "",
							  const iTelegramMessageKeyboard *replyMarkup = nullptr) {
		sendPhoto(chatId, fileId, caption, parseMode, disableNotification, replyToMessageId, replyMarkup, true);
	}
	inline void sendPhotoByUrl(const QString &chatId,
							   const QString &url,
							   const QString &caption = "",
							   const QString &parseMode = "",
							   const bool &disableNotification = false,
							   const QString &replyToMessageId = "",
							   const iTelegramMessageKeyboard *replyMarkup = nullptr) {
		sendPhoto(chatId, url, caption, parseMode, disableNotification, replyToMessageId, replyMarkup, true);
	}
	inline void sendPhotoByPath(const QString &chatId,
								const QString &filePath,
								const QString &caption = "",
								const QString &parseMode = "",
								const bool &disableNotification = false,
								const QString &replyToMessageId = "",
								const iTelegramMessageKeyboard *replyMarkup = nullptr) {
		sendPhoto(chatId, filePath, caption, parseMode, disableNotification, replyToMessageId, replyMarkup, false);
	}

	inline void sendVideoById(const QString &chatId,
					   const QString &fileId,
					   const int &duration = -1,
					   const int &width = -1,
					   const int &height = -1,
					   const QString &thumb = "",
					   const QString &caption = "",
					   const QString &parseMode = "",
					   const bool &supportsStreaming = false,
					   const bool &disableNotification = false,
					   const QString &replyToMessageId = "",
					   const iTelegramMessageKeyboard *replyMarkup = nullptr) {
		sendVideo(chatId, fileId, duration, width, height, thumb, caption, parseMode, supportsStreaming, disableNotification, replyToMessageId, replyMarkup, true);
	}

	inline void sendVideoByUrl(const QString &chatId,
						const QString &url,
						const int &duration = -1,
						const int &width = -1,
						const int &height = -1,
						const QString &thumb = "",
						const QString &caption = "",
						const QString &parseMode = "",
						const bool &supportsStreaming = false,
						const bool &disableNotification = false,
						const QString &replyToMessageId = "",
						const iTelegramMessageKeyboard *replyMarkup = nullptr) {
		sendVideo(chatId, url, duration, width, height, thumb, caption, parseMode, supportsStreaming, disableNotification, replyToMessageId, replyMarkup, true);
	}

	inline void sendVideoByPath(const QString &chatId,
						 const QString &filePath,
						 const int &duration = -1,
						 const int &width = -1,
						 const int &height = -1,
						 const QString &thumb = "",
						 const QString &caption = "",
						 const QString &parseMode = "",
						 const bool &supportsStreaming = false,
						 const bool &disableNotification = false,
						 const QString &replyToMessageId = "",
						 const iTelegramMessageKeyboard *replyMarkup = nullptr){
		sendVideo(chatId, filePath, duration, width, height, thumb, caption, parseMode, supportsStreaming, disableNotification, replyToMessageId, replyMarkup, false);
	}

	void sendAudio(const QString &chatId,
				   const QString &urlFileOrFileId,
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const int duration = -1,
				   const QString &performer = "",
				   const QString &title = "",
				   const QString &thumb = "",
				   const bool &disableNotification = false,
				   const QString replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	void sendVideoNote(const QString &chatId,
					   const QString &urlFileOrFileId,
					   const int &duration = -1,
					   const int &length = -1,
					   const QString &thumb = "",
					   const bool &disableNotification = false,
					   const QString &replyToMessageId = "",
					   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendMediaGroup(const QString &chatId,
						const QStringList &urlFilesOrFileIds,
						const bool &disableNotification = false,
						const QString &replyToMessageId = "");
	void sendDocument(const QString &chatId,
					  const QString &urlFileOrFileId,
					  const QString &thumb = "",
					  const QString &caption = "",
					  const QString &parseMode = "",
					  const bool &disableNotification = false,
					  const QString &replyToMessageId = "",
					  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendAnimation(const QString &chatId,
					   const QString &urlFileOrFileId,
					   const QString &thumb = "",
					   const QString &caption = "",
					   const QString &parseMode = "",
					   const bool &disableNotification = false,
					   const QString &replyToMessageId = "",
					   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendVoice(const QString &chatId,
				   const QString &urlFileOrFileId,
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const int &duration = -1,
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	void sendChatAction(const QString &chatId, const QString &chatAction);
	void sendChatAction(const QString &chatId, const ChatAction &chatAction);
	void sendLocation(const QString &chatId,
					  const double &latitude,
					  const double &longitude,
					  const int &livePeriod = -1,
					  const bool &disableNotification = false,
					  const QString &replyToMessageId = "",
					  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendVenue(const QString& chatId,
				   const double &latitude,
				   const double &longitude,
				   const QString &title,
				   const QString &address,
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendContact(const QString &chatId,
					 const QString &phoneNumber,
					 const QString &firstName,
					 const QString &lastName,
					 const QString &about = "",
					 const bool disableNotification = false,
					 const QString &replyToMessageId = "",
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendPoll(const QString& chatId,
				  const QString &question,
				  const QStringList &optionsList,
				  const bool disableNotification = false,
				  const QString &replyToMessageId = "",
				  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	void sendSticker(const QString &chatId,
					 const QString &url,
					 const bool &disableNotification = false,
					 const QString &replyToMessageId = "",
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);

	void getFile(const QString &fileId);
	void getStickerSet(const QString &name);

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

	void deleteMessage(const QString &chatId,
					   const QString &messageId);

	void downloadFile(const QString &fileId);

	static QTcpServer *createListenServer(const quint16 port);
	void deleteListenServer();
signals:
	void errored(const QString &error);

	void messaged(const TelegramMessage *message);
	void exportChatInviteLinked(const QString &joinLink);

	void botMessaged(const TelegramMessage *message);

	void getStickerSetReady(const TelegramStickerSet &stickerSet);
	void getChatReady(const TelegramChat &chat);

	void getFileReady(const TelegramFile &file);

	void fileDownloaded(const QString &fileName,
						const QByteArray &array);
private slots:
	void onGetUpdates(const QJsonObject &resultObject);
	void onGetUpdates(const QJsonValueRef &resultObject);
	void onGetUpdates(TelegramRequest *telegramRequest);

	void onTelegramRequestReply(TelegramRequest *telegramRequest);



private:
	bool m_isPolled;
	QString m_token;
	QNetworkAccessManager *m_manager;

	QTcpServer* m_listenServer;

	int m_updateOffset;
	bool m_mayUpdates;

	void sendPhoto(const QString &chatId,
				   const QString &fileId,
				   const QString &caption,
				   const QString &parseMode,
				   const bool &disableNotification,
				   const QString &replyToMessageId,
				   const iTelegramMessageKeyboard *replyMarkup,
				   const bool &json);

	void sendVideo(const QString &chatId,
				   const QString &urlFileOrFileId,
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
				   const bool &json);

	void jsonSend(const QString &title,
				  const QJsonObject &json = QJsonObject(),
				  const TelegramRequest::RequestType &requestType = TelegramRequest::Unknown);

	void multipartSend(const QString &title,
					   const QJsonObject &json,
					   const QHttpPart &part);

	QHttpPart packFile(const QString &path,
					   const QString &fieldname);
	inline QHttpPart packPhoto(const QString &path) {
		return packFile(path, "photo");
	}
	inline QHttpPart packVideo(const QString &path) {
		return packFile(path, "video");
	}
};

#endif // TELEGRAMBOT_H
