#ifndef TELEGRAMMESSAGE_H
#define TELEGRAMMESSAGE_H

#include "telegrambasetypes.h"
#include "payments/telegramsuccessfulpayment.h"
#include "telegramchat.h"
#include "telegramuser.h"
#include "telegramaudio.h"
#include "telegramdocument.h"
#include "telegramvideo.h"
#include "telegramvideonote.h"
#include "telegramvoice.h"
#include "telegramanimation.h"
#include "telegramcontact.h"
#include "telegramphotosize.h"
#include "telegrammessageentity.h"
#include "telegramlocation.h"
#include "telegramvenue.h"
#include "telegrampoll.h"
#include "telegraminlinekeyboardmarkup.h"
#include "stickers/telegramsticker.h"
#include "payments/telegraminvoice.h"
#include "payments/telegramsuccessfulpayment.h"
#include "passport/telegrampassportdata.h"

class TelegramGame;

class TelegramMessage : public TelegramBaseTypes
{
public:
	explicit TelegramMessage(const QJsonObject &json);
	//TelegramMessage(const TelegramMessage &message);
	~TelegramMessage();

	QString id() const { return m_id; }
	TelegramUser from() const { return m_from; }
	int date() const { return m_date; }
	TelegramChat chat() const { return m_chat; }
	TelegramUser forwardFrom() const { return m_forwardFrom; }
	TelegramChat forwardFromChat() const { return m_forwardFromChat; }
	QString forwardFromMessageId() const { return m_forwardFromMessageId; }
	QString forwardSignature() const { return m_forwardSignature; }
	QString senderName() const { return m_senderName; }
	int forwardDate() const { return m_forwardDate; }
	TelegramMessage replyToMessage() const { return m_replyToMessage == nullptr ?
					TelegramMessage(QJsonObject()) : *m_replyToMessage; }
	int editDate() const { return  m_editDate; }
	QString mediaGroupId() const { return m_mediaGroupId; }
	QString autorSignature() const { return m_autorSignature;}
	QString text() const { return m_text; }
	QList<TelegramMessageEntity> entities() const { return m_entities; }
	QList<TelegramMessageEntity> captionEntities() const { return m_captionEntities; }
	TelegramAudio audio() const { return m_audio; }
	TelegramDocument document() const { return m_document; }
	TelegramAnimation animation() const { return m_animation; }
	QList<TelegramPhotoSize> photo() const { return m_photo;}
	TelegramGame *game() const;
	TelegramSticker sticker() const { return m_sticker; }
	TelegramVideo video() const { return m_video; }
	TelegramVoice voice() const { return m_voice; }
	QString caption() const { return m_caption; }
	TelegramContact contact() const { return m_contact; }
	TelegramLocation location() const { return m_location; }
	TelegramVenue venue() const { return m_venue; }
	TelegramPoll poll() const { return m_poll; }
	QList<TelegramUser> newChatMembers() const { return m_newChatMembers; }
	TelegramUser leftChatMember() const { return m_leftChatMember; }
	QString newChatTitle() const { return m_newChatTitle; }
	QList<TelegramPhotoSize> newChatPhoto() const { return m_newChatPhoto; }
	bool deleteChatPhoto() const { return m_deleteChatPhoto; }
	bool groupChatCreated() const { return m_groupChatCreated; }
	bool supergroupChatCreated() const { return m_supergroupChatCreated; }
	bool channelChatCreate() const { return m_channelChatCreate; }
	QString migrateToChatId() const { return m_mediaGroupId; }
	QString migrateFromChatId() const { return m_migrateFromChatId; }
	TelegramMessage pinnedMessage() const { return m_pinnedMessage == nullptr ?
					TelegramMessage(QJsonObject()) : *m_pinnedMessage; }
	TelegramInvoice invoice() const { return m_invoice; }
	TelegramSuccessfulPayment successfulPayment() const { return m_successfulPayment; }
	QString connectedWebsite() const { return m_connectedWebsite; }
	TelegramPassportData passportData() const { return m_passportData; }
	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }

private:
	QString m_id;
	TelegramUser m_from;
	int m_date;
	TelegramChat m_chat;
	TelegramUser m_forwardFrom;
	TelegramChat m_forwardFromChat;
	QString m_forwardFromMessageId;
	QString m_forwardSignature;
	QString m_senderName;
	int m_forwardDate;
	TelegramMessage *m_replyToMessage;
	int m_editDate;
	QString m_mediaGroupId;
	QString m_autorSignature;
	QString m_text;
	QList<TelegramMessageEntity> m_entities;
	QList<TelegramMessageEntity> m_captionEntities;
	TelegramAudio m_audio;
	TelegramDocument m_document;
	TelegramAnimation m_animation;
	TelegramGame *m_game;
	QList<TelegramPhotoSize> m_photo;
	TelegramSticker m_sticker;
	TelegramVideo m_video;
	TelegramVoice m_voice;
	QString m_caption;
	TelegramContact m_contact;
	TelegramLocation m_location;
	TelegramVenue m_venue;
	TelegramPoll m_poll;
	QList<TelegramUser> m_newChatMembers;
	TelegramUser m_leftChatMember;
	QString m_newChatTitle;
	QList<TelegramPhotoSize> m_newChatPhoto;
	bool m_deleteChatPhoto;
	bool m_groupChatCreated;
	bool m_supergroupChatCreated;
	bool m_channelChatCreate;
	QString m_migrateToChatId;
	QString m_migrateFromChatId;
	TelegramMessage *m_pinnedMessage;
	TelegramInvoice m_invoice;
	TelegramSuccessfulPayment m_successfulPayment;
	QString m_connectedWebsite;
	TelegramPassportData m_passportData;
	TelegramInlineKeyboardMarkup m_replyMarkup;
};

#endif // TELEGRAMMESSAGE_H
