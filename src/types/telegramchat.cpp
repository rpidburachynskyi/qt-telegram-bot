#include "telegramchat.h"
#include "telegramchatphoto.h"
#include "telegrammessage.h"
#include "telegramchatpermissions.h"
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
	m_message = (json.contains("message")) ? new TelegramMessage(json["message"].toObject()) : nullptr;
	m_chatPermissions = (json.contains("chat_permissions")) ? new TelegramChatPermissions(json["chat_permissions"].toObject()) : nullptr;
	m_stickerSetName = json["sticker_set_name"].toString("");
	m_canStickerSet = json["can_sticker_set"].toBool();
}

TelegramChat::TelegramChat(const TelegramChat &chat)
{
	m_photo = (chat.m_photo) ? new TelegramChatPhoto(*chat.m_photo) : m_photo = nullptr;
	m_message = (chat.m_message) ? new TelegramMessage(*chat.m_message) : nullptr;
	m_chatPermissions = (chat.m_chatPermissions) ? new TelegramChatPermissions(*chat.m_chatPermissions) : nullptr;


	m_id = chat.m_id;
	m_type = chat.m_type;
	m_title = chat.m_title;
	m_username = chat.m_username;
	m_firstName = chat.m_firstName;
	m_lastName = chat.m_lastName;
	m_description = chat.m_description;
	m_inviteLink = chat.m_inviteLink;
	m_stickerSetName = chat.m_stickerSetName;
	m_canStickerSet = chat.m_canStickerSet;
}

TelegramChat::~TelegramChat()
{
	delete m_photo;
	delete m_message;
	delete m_chatPermissions;
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

QString TelegramChat::description() const
{
	return m_description;
}

QString TelegramChat::inviteLink() const
{
	return m_inviteLink;
}

TelegramMessage *TelegramChat::message() const
{
	return m_message;
}

TelegramChatPermissions *TelegramChat::chatPermissions() const
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
