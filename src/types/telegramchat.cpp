#include "telegramchat.h"
#include "telegramchatphoto.h"
#include <QVariant>

TelegramChat::TelegramChat(const QJsonObject &json)
{
	m_id = json["id"].toVariant().toString();
	m_type = json["type"].toString();
	m_title = json["title"].toString("");
	m_username = json["username"].toString("");
	m_firstName = json["first_name"].toString("");
	m_lastName = json["last_name"].toString("");
	m_photo = (json.contains("photo")) ? new TelegramChatPhoto(json["photo"].toObject()) : nullptr;
	m_description = json["description"].toString("");
	m_inviteLink = json["inviteLink"].toString("");

	m_stickerSetName = json["sticker_set_name"].toString("");
}

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

TelegramChatPhoto *TelegramChat::photo() const
{
	return m_photo;
}
