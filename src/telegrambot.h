#ifndef TELEGRAMBOT_H
#define TELEGRAMBOT_H

#include "requests/telegramrequest.h"
#include "requests/telegramrequestdownload.h"
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
#include "types/telegraminputfile.h"
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

	TelegramRequest* setWebhook(QTcpServer *server,
					const QString &url,
					const int &maxConnection = 40,
					const QStringList &allowedUpdates = {});
	TelegramRequest* deleteWebhook();
	TelegramRequest* getWebhookInfo();

	TelegramRequest* sendMessage(const QString &id,
					 const QString &text,
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* sendMessage(const QString &id,
					 const QString &text,
					 const QString &m_parseMode,
					 const bool &disableWebPagePreview = false,
					 const bool &disableNofitication = false,
					 const int &replyToMessageId = -1,
					 const TelegramReplyKeyboardMarkup *replyMarkup = nullptr);

	TelegramRequest* forwardMessage(const QString &chatId,
						const int &fromChatId,
						bool disableNotification,
						const int& messageId);

	TelegramRequest* sendPhoto(const QString &chatId,
				   const TelegramInputFile &inputFile,
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* sendVideo(const QString &chatId,
				   const TelegramInputFile &inputFile,
				   const int &duration = -1,
				   const int &width = -1,
				   const int &height = -1,
				   const QString &thumb = "",
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const bool &supportsStreaming = false,
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* sendAudio(const QString &chatId,
				   const TelegramInputFile &inputFile,
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const int duration = -1,
				   const QString &performer = "",
				   const QString &title = "",
				   const QString &thumb = "",
				   const bool &disableNotification = false,
				   const QString replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* sendVideoNote(const QString &chatId,
					   const TelegramInputFile &inputFile,
					   const int &duration = -1,
					   const int &length = -1,
					   const QString &thumb = "",
					   const bool &disableNotification = false,
					   const QString &replyToMessageId = "",
					   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendMediaGroup(const QString &chatId,
						const QStringList &urlFilesOrFileIds,
						const bool &disableNotification = false,
						const QString &replyToMessageId = "");
	TelegramRequest* sendDocument(const QString &chatId,
					  const TelegramInputFile &inputFile,
					  const QString &thumb = "",
					  const QString &caption = "",
					  const QString &parseMode = "",
					  const bool &disableNotification = false,
					  const QString &replyToMessageId = "",
					  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendAnimation(const QString &chatId,
					   const TelegramInputFile &inputFile,
					   const QString &thumb = "",
					   const QString &caption = "",
					   const QString &parseMode = "",
					   const bool &disableNotification = false,
					   const QString &replyToMessageId = "",
					   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendVoice(const QString &chatId,
				   const TelegramInputFile &inputFile,
				   const QString &caption = "",
				   const QString &parseMode = "",
				   const int &duration = -1,
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* sendChatAction(const QString &chatId, const QString &chatAction);
	TelegramRequest* sendChatAction(const QString &chatId, const ChatAction &chatAction);
	TelegramRequest* sendLocation(const QString &chatId,
					  const double &latitude,
					  const double &longitude,
					  const int &livePeriod = -1,
					  const bool &disableNotification = false,
					  const QString &replyToMessageId = "",
					  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendVenue(const QString& chatId,
				   const double &latitude,
				   const double &longitude,
				   const QString &title,
				   const QString &address,
				   const bool &disableNotification = false,
				   const QString &replyToMessageId = "",
				   const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendContact(const QString &chatId,
					 const QString &phoneNumber,
					 const QString &firstName,
					 const QString &lastName,
					 const QString &about = "",
					 const bool disableNotification = false,
					 const QString &replyToMessageId = "",
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendPoll(const QString& chatId,
				  const QString &question,
				  const QStringList &optionsList,
				  const bool disableNotification = false,
				  const QString &replyToMessageId = "",
				  const iTelegramMessageKeyboard *replyMarkup = nullptr);
	TelegramRequest* sendSticker(const QString &chatId,
					 const QString &url,
					 const bool &disableNotification = false,
					 const QString &replyToMessageId = "",
					 const iTelegramMessageKeyboard *replyMarkup = nullptr);

	TelegramRequest* getFile(const QString &fileId);
	TelegramRequest* getStickerSet(const QString &name);

	TelegramRequest* getMe();

	TelegramRequest* kickChatMember(const QString &chatId,
						const QString &userId,
						const int &untilDate = 0);

	TelegramRequest* unbanChatMember(const QString &chatId,
						 const int &userId);

	TelegramRequest* restrictChatMember(const QString &chatId,
							const int &userId,
							const TelegramChatPermissions *permissions,
							const int &untilDate = 0);

	TelegramRequest* promoteChatMember(const QString &chatId,
						   const int &userId,
						   const bool &canChangeInfo,
						   const bool &canPostMessage,
						   const bool &canEditMessage,
						   const bool &canDeleteMessage,
						   const bool &canInviteUsers,
						   const bool &canRestrictMembers,
						   const bool &canPinMessages,
						   const bool &canPromoteMembers);

	TelegramRequest* setChatPermissions(const QString &chatId,
							const TelegramChatPermissions &permissions);

	TelegramRequest* exportChatInviteLink(const QString &chatId);

	TelegramRequest* setChatPhoto(); // FIXIT
	TelegramRequest* deleteChatPhoto(const QString &chatId);
	TelegramRequest* setChatTitle(const QString &chatId, const QString &title);
	TelegramRequest* setChatDescription(const QString &chatId, const QString &description);

	TelegramRequest* pinChatMessage(const QString &chatId,
						const QString &messageId,
						const bool &disableNotification);
	TelegramRequest* unpinChatMessage(const QString &chatId);

	TelegramRequest* leaveChat(const QString &chatId);
	TelegramRequest* getChat(const QString &chatId);
	TelegramRequest* getChatAdministators(const QString &chatId);
	TelegramRequest* getChatMemberCount(const QString &chatId);
	TelegramRequest* getChatMember(const QString &chatId, const QString &userId);

	TelegramRequest* setChatStickerSet(const QString &chatId, const QString &stickerSetName);
	TelegramRequest* deleteChatStickerSet(const QString &chatId);

	TelegramRequest* editMessageText(const QString &chatId,
						 const int &messageId,
						 const QString &newText,
						 const QString &parseMode = "",
						 const bool &disableWebPagePreview = false);

	TelegramRequest* editMessageCaption(const QString &chatId,
							const int &messageId,
							const QString &newCaption,
							const QString &parseMode = "",
							const bool &disableWebPagePreview = false);

	TelegramRequest* editMessageMedia(const QString &chatId,
						  const QString &messageId,
						  const TelegramInputMedia &inputMedia);

	TelegramRequest* deleteMessage(const QString &chatId,
					   const QString &messageId);

	TelegramRequestDownload *downloadFile(const QString &fileId);

	static QTcpServer *createListenServer(const quint16 port);
	void deleteListenServer();
signals:
	void errored(const QString &error);
	void messaged(const TelegramMessage *message);

private slots:
	void onGetUpdatesFinished(const bool &ok);
	void onGetUpdates(const QJsonObject &resultObject);

private:
	bool m_isPolled;
	QString m_token;
	QNetworkAccessManager *m_manager;

	QTcpServer* m_listenServer;

	int m_updateOffset;
	bool m_mayUpdates;

	void getUpdates();

	TelegramRequest* jsonSend(const QString &title,
				  const QJsonObject &json = QJsonObject());

	TelegramRequest* multipartSend(const QString &title,
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
	inline QHttpPart packAudio(const QString &path) {
		return packFile(path, "audio");
	}
	inline QHttpPart packVoice(const QString &path) {
		return packFile(path, "voice");
	}
	inline QHttpPart packVideoNote(const QString &path) {
		return packFile(path, "video_note");
	}
	inline QHttpPart packVoiceNote(const QString &path) {
		return packFile(path, "voice_note");
	}
	inline QHttpPart packAnimation(const QString &path) {
		return packFile(path, "animation");
	}
	inline QHttpPart packDocument(const QString &path) {
		return packFile(path, "document");
	}
};

#endif // TELEGRAMBOT_H
