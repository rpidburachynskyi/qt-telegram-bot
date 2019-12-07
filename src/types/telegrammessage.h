#ifndef TELEGRAMMESSAGE_H
#define TELEGRAMMESSAGE_H

#include "payments/telegramsuccessfulpayment.h"
#include <QList>

class TelegramUser;
class TelegramChat;
class TelegramMessageEntity;
class TelegramAudio;
class TelegramDocument;
class TelegramAnimation;
class TelegramGame;
class TelegramPhotoSize;
class TelegramSticker;
class TelegramVideo;
class TelegramVoice;
class TelegramVideoNote;
class TelegramContact;
class TelegramLocation;
class TelegramVenue;
class TelegramPoll;
class TelegramLeftNewChatMember;
class TelegramNewChatPhoto;
class TelegramInvoice;
class TelegramSuccessfulPayment;
class TelegramPassportData;
class TelegramReplyMarkup;
class TelegramInlineKeyboardMarkup;

class TelegramMessage
{
public:
	explicit TelegramMessage(const QJsonObject &json);
	explicit TelegramMessage(const TelegramMessage &message);

	QString id() const { return m_id; }
	TelegramUser *from() const;
	int date() const;
	TelegramChat *chat() const;
	TelegramUser *forwardFrom() const;
	TelegramChat *forwardFromChat() const;
	QString forwardFromMessageId() const;
	QString forwardSignature() const;
	QString senderName() const;
	int forwardDate() const;
	TelegramMessage *replyToMessage() const;
	int editDate() const;
	QString mediaGroupId() const;
	QString autorSignature() const;
	QString text() const;
	QList<TelegramMessageEntity *> entities() const;
	QList<TelegramMessageEntity *> captionEntities() const;
	TelegramAudio *audio() const;
	TelegramDocument *document() const;
	TelegramAnimation *animation() const;
	QList<TelegramPhotoSize *> photo() const;
	TelegramGame *game() const;
	TelegramSticker *sticker() const;
	TelegramVideo *video() const;
	TelegramVoice *voice() const;
	QString caption() const;
	TelegramContact *contact() const;
	TelegramLocation *location() const;
	TelegramVenue *venue() const;
	TelegramPoll *poll() const;
	QList<TelegramUser *> newChatMembers() const;
	TelegramUser *leftChatMember() const;
	QString newChatTitle() const;
	QList<TelegramPhotoSize *> newChatPhoto() const;
	bool deleteChatPhoto() const;
	bool groupChatCreated() const;
	bool supergroupChatCreated() const;
	bool channelChatCreate() const;
	QString migrateToChatId() const;
	QString migrateFromChatId() const;
	TelegramMessage *pinnedMessage() const;
	TelegramInvoice *invoice() const;
	TelegramSuccessfulPayment *successfulPayment() const;
	QString connectedWebsite() const;
	TelegramPassportData *passportData() const;
	TelegramInlineKeyboardMarkup *replyMarkup() const;

private:
	QString m_id;
	TelegramUser *m_from;
	int m_date;
	TelegramChat *m_chat;
	TelegramUser *m_forwardFrom;
	TelegramChat *m_forwardFromChat;
	QString m_forwardFromMessageId;
	QString m_forwardSignature;
	QString m_senderName;
	int m_forwardDate;
	TelegramMessage *m_replyToMessage;
	int m_editDate;
	QString m_mediaGroupId;
	QString m_autorSignature;
	QString m_text;
	QList<TelegramMessageEntity *> m_entities;
	QList<TelegramMessageEntity *> m_captionEntities;
	TelegramAudio *m_audio;
	TelegramDocument *m_document;
	TelegramAnimation *m_animation;
	TelegramGame *m_game;
	QList<TelegramPhotoSize *> m_photo;
	TelegramSticker *m_sticker;
	TelegramVideo *m_video;
	TelegramVoice *m_voice;
	QString m_caption;
	TelegramContact *m_contact;
	TelegramLocation *m_location;
	TelegramVenue *m_venue;
	TelegramPoll *m_poll;
	QList<TelegramUser *> m_newChatMembers;
	TelegramUser *m_leftChatMember;
	QString m_newChatTitle;
	QList<TelegramPhotoSize *> m_newChatPhoto;
	bool m_deleteChatPhoto;
	bool m_groupChatCreated;
	bool m_supergroupChatCreated;
	bool m_channelChatCreate;
	QString m_migrateToChatId;
	QString m_migrateFromChatId;
	TelegramMessage *m_pinnedMessage;
	TelegramInvoice *m_invoice;
	TelegramSuccessfulPayment *m_successfulPayment;
	QString m_connectedWebsite;
	TelegramPassportData *m_passportData;
	TelegramInlineKeyboardMarkup *m_replyMarkup;
};

#endif // TELEGRAMMESSAGE_H
