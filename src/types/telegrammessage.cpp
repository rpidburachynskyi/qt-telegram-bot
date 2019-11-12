#include "telegrammessage.h"
#include "telegramchat.h"
#include "telegramuser.h"
#include "telegramaudio.h"
#include "telegramdocument.h"
#include "telegramvideo.h"
#include "telegramvideonote.h"
#include "telegramvoice.h"
#include "telegramanimation.h"
#include "telegramcontact.h"
#include "telegrammessageentity.h"

#include <QVariant>
#include <QJsonArray>

TelegramMessage::TelegramMessage(const QJsonObject &json)
{
	m_id = json["message_id"].toVariant().toString();
	m_date = json["date"].toInt();
	if(json.contains("from")) m_from = new TelegramUser(json["from"].toObject());
	m_chat = json.contains("chat") ? new TelegramChat(json["chat"].toObject()) : nullptr;
	if(json.contains("text")) m_text = json["text"].toString();

	if(json.contains("audio")) m_audio = new TelegramAudio(json["audio"].toObject());
	if(json.contains("document")) m_document = new TelegramDocument(json["document"].toObject());
	if(json.contains("video")) m_video = new TelegramVideo(json["video"].toObject());

	if(json.contains("contact")) m_contact = new TelegramContact(json["video"].toObject());



	if(json.contains("entities"))
	{
		QJsonArray entities = json["entities"].toArray();
		for(auto entityObject : entities)
		{
			TelegramMessageEntity *entity = new TelegramMessageEntity(entityObject.toObject());
			m_entities.append(entity);
		}
	}
}

QString TelegramMessage::id() const
{
	return m_id;
}

TelegramUser *TelegramMessage::from() const
{
	return m_from;
}

int TelegramMessage::date() const
{
	return m_date;
}

TelegramChat *TelegramMessage::chat() const
{
	return m_chat;
}

TelegramUser *TelegramMessage::forwardFrom() const
{
	return m_forwardFrom;
}

TelegramChat *TelegramMessage::forwardFromChat() const
{
	return m_forwardFromChat;
}

QString TelegramMessage::forwardFromMessageId() const
{
	return m_forwardFromMessageId;
}

QString TelegramMessage::forwardSignature() const
{
	return m_forwardSignature;
}

QString TelegramMessage::senderName() const
{
	return m_senderName;
}

int TelegramMessage::forwardDate() const
{
	return m_forwardDate;
}

TelegramMessage *TelegramMessage::replyToMessage() const
{
	return m_replyToMessage;
}

int TelegramMessage::editDate() const
{
	return m_editDate;
}

QString TelegramMessage::mediaGroupId() const
{
	return m_mediaGroupId;
}

QString TelegramMessage::autorSignature() const
{
	return m_autorSignature;
}

QString TelegramMessage::text() const
{
	return m_text;
}

QList<TelegramMessageEntity *> TelegramMessage::entities() const
{
	return m_entities;
}

QList<TelegramMessageEntity *> TelegramMessage::captionEntities() const
{
	return m_captionEntities;
}

TelegramAudio *TelegramMessage::audio() const
{
	return m_audio;
}

TelegramDocument *TelegramMessage::document() const
{
	return m_document;
}

TelegramAnimation *TelegramMessage::animation() const
{
	return m_animation;
}

TelegramGame *TelegramMessage::game() const
{
	return m_game;
}

TelegramSticker *TelegramMessage::sticker() const
{
	return m_sticker;
}

TelegramVideo *TelegramMessage::video() const
{
	return m_video;
}

TelegramVoice *TelegramMessage::voice() const
{
	return m_voice;
}

QString TelegramMessage::caption() const
{
	return m_caption;
}

TelegramContact *TelegramMessage::contact() const
{
	return m_contact;
}

TelegramLocation *TelegramMessage::location() const
{
	return m_location;
}

TelegramVenue *TelegramMessage::venue() const
{
	return m_venue;
}

TelegramPoll *TelegramMessage::poll() const
{
	return m_poll;
}

QList<TelegramNewChatMember *> TelegramMessage::newChatMembers() const
{
	return m_newChatMembers;
}

TelegramNewChatMember *TelegramMessage::leftChatMember() const
{
	return m_leftChatMember;
}

QString TelegramMessage::newChatTitle() const
{
	return m_newChatTitle;
}

QList<TelegramPhoto *> TelegramMessage::newChatPhoto() const
{
	return m_newChatPhoto;
}

bool TelegramMessage::deleteChatPhoto() const
{
	return m_deleteChatPhoto;
}

bool TelegramMessage::groupChatCreated() const
{
	return m_groupChatCreated;
}

bool TelegramMessage::supergroupChatCreated() const
{
	return m_supergroupChatCreated;
}

bool TelegramMessage::channelChatCreate() const
{
	return m_channelChatCreate;
}

QString TelegramMessage::migrateToChatId() const
{
	return m_migrateToChatId;
}

QString TelegramMessage::migrateFromChatId() const
{
	return m_migrateFromChatId;
}

TelegramMessage *TelegramMessage::pinnedMessage() const
{
	return m_pinnedMessage;
}

TelegramInvoice *TelegramMessage::invoice() const
{
	return m_invoice;
}

TelegramSuccessfulPayment *TelegramMessage::successfulPayment() const
{
	return m_successfulPayment;
}

QString TelegramMessage::connectedWebsite() const
{
	return m_connectedWebsite;
}

TelegramPasportData *TelegramMessage::passportData() const
{
	return m_passportData;
}

TelegramInlineKeyboardMarkup *TelegramMessage::replyMarkup() const
{
	return m_replyMarkup;
}
