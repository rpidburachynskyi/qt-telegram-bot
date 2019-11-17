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
#include "telegramlocation.h"
#include "telegramvenue.h"
#include "telegrampoll.h"
#include "telegramleftnewchatmember.h"
#include "stickers/telegramsticker.h"
#include "telegraminvoice.h"

#include <QVariant>
#include <QJsonArray>

TelegramMessage::TelegramMessage(const QJsonObject &json)
{
	m_id = json["message_id"].toVariant().toString();
	m_date = json["date"].toInt();
	m_from = (json.contains("from")) ? new TelegramUser(json["from"].toObject()) : nullptr;
	m_chat = json.contains("chat") ? new TelegramChat(json["chat"].toObject()) : nullptr;
	m_text = json["text"].toString("");

	m_forwardFrom = (json.contains("forward_from")) ? new TelegramUser(json["forward_from"].toObject()) : nullptr;
	m_forwardFromChat = (json.contains("forward_from_chat")) ? new TelegramChat(json["forward_from_chat"].toObject()) : nullptr;

	m_forwardFromMessageId = json["forward_from_message_id"].toString("");
	m_forwardSignature = json["forward_signature"].toString("");
	m_senderName = json["forward_signature"].toString("");
	m_forwardDate = json["forward_date"].toInt();

	m_replyToMessage = (json.contains("reply_to_message")) ? new TelegramMessage(json["reply_to_message"].toObject()) : nullptr;

	m_editDate = json["edit_date"].toInt();

	m_mediaGroupId = json["media_group"].toString("");
	m_autorSignature = json["autor_signature"].toString("");

	m_animation = (json.contains("animation")) ? new TelegramAnimation(json["animation"].toObject()) : nullptr;
	m_audio = (json.contains("audio")) ? new TelegramAudio(json["audio"].toObject()) : nullptr;
	m_document = (json.contains("document")) ? new TelegramDocument(json["document"].toObject()) : nullptr;
	m_video = (json.contains("video")) ? new TelegramVideo(json["video"].toObject()) : nullptr;
	m_voice = (json.contains("voice")) ? new TelegramVoice(json["voice"].toObject()) : nullptr;
	m_sticker = (json.contains("sticker")) ? new TelegramSticker(json["sticker"].toObject()) : nullptr;

	m_caption = json["caption"].toString("");

	m_contact = (json.contains("contact")) ? new TelegramContact(json["contact"].toObject()) : nullptr;
	m_location = (json.contains("location")) ? new TelegramLocation(json["location"].toObject()) : nullptr;
	m_venue = (json.contains("venue")) ? new TelegramVenue(json["venue"].toObject()) : nullptr;
	m_poll = (json.contains("poll")) ? new TelegramPoll(json["poll"].toObject()) : nullptr;

	m_leftChatMember = (json.contains("left_chat_member")) ? new TelegramLeftNewChatMember(json["left_chat_member"].toObject()) : nullptr;

	m_newChatTitle = json["new_chat_title"].toString("");

	m_deleteChatPhoto = json["delete_chat_photo"].toBool();
	m_groupChatCreated = json["delete_chat_photo"].toBool();
	m_supergroupChatCreated = json["delete_chat_photo"].toBool();
	m_channelChatCreate = json["delete_chat_photo"].toBool();

	m_migrateToChatId = json["migrate_to_chat_id"].toString("");
	m_migrateFromChatId = json["migrate_from_chat_id"].toString("");

	m_pinnedMessage = (json.contains("pinned_message")) ? new TelegramMessage(json["pinned_message"].toObject()) : nullptr;

	m_invoice = (json.contains("invoice")) ? new TelegramInvoice(json["invoice"].toObject()) : nullptr;


	if(json.contains("entities"))
	{
		QJsonArray entities = json["entities"].toArray();
		for(auto entityObject : entities)
		{
			TelegramMessageEntity *entity = new TelegramMessageEntity(entityObject.toObject());
			m_entities.append(entity);
		}
	}

	if(json.contains("new_chat_members"))
	{
		QJsonArray members = json["new_chat_members"].toArray();
		for(auto member : members)
		{
			TelegramLeftNewChatMember *newMember = new TelegramLeftNewChatMember(member.toObject());

			m_newChatMembers.append(newMember);
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

QList<TelegramLeftNewChatMember *> TelegramMessage::newChatMembers() const
{
	return m_newChatMembers;
}

TelegramLeftNewChatMember *TelegramMessage::leftChatMember() const
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
