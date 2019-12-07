#include "telegramchat.h"
#include "telegrammessage.h"
#include <QVariant>

TelegramChat::TelegramChat(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_id(json["id"].toVariant().toString()),
	  m_type(json["type"].toString()),
	  m_title(json["title"].toString("")),
	  m_username(json["username"].toString("")),
	  m_firstName(json["first_name"].toString("")),
	  m_lastName(json["last_name"].toString("")),
	  m_photo(json["photo"].toObject()),
	  m_description(json["description"].toString("")),
	  m_inviteLink(json["inviteLink"].toString("")),
	  m_message(json.contains("message") ? new TelegramMessage(json["message"].toObject()) : nullptr),
	  m_chatPermissions(json["chat_permissions"].toObject()),
	  m_stickerSetName(json["sticker_set_name"].toString("")),
	  m_canStickerSet(json["can_sticker_set"].toBool())
{ }

QString TelegramChat::id() const
{
	return m_id;
}

QString TelegramChat::type() const
{
	return m_type;
}

QString TelegramChat::title() const
{
	return m_title;
}

QString TelegramChat::username() const
{
	return m_username;
}

QString TelegramChat::firstName() const
{
	return m_firstName;
}

QString TelegramChat::lastName() const
{
	return m_lastName;
}

TelegramChatPhoto TelegramChat::photo() const
{
	return m_photo;
}

QString TelegramChat::description() const
{
	return m_description;
}

QString TelegramChat::inviteLink() const
{
	return m_inviteLink;
}

TelegramMessage TelegramChat::message() const
{
	if(m_message)
		return *m_message;
	return TelegramMessage(QJsonObject());
}

TelegramChatPermissions TelegramChat::chatPermissions() const
{
	return m_chatPermissions;
}

QString TelegramChat::stickerSetName() const
{
	return m_stickerSetName;
}

bool TelegramChat::canStickerSet() const
{
	return m_canStickerSet;
}
