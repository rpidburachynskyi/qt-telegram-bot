#include "telegrammessageentity.h"

#include "telegramuser.h"

TelegramMessageEntity::TelegramMessageEntity(const QJsonObject &json)
{
	m_type = json["type"].toString();
	m_offset = json["offset"].toInt();
	m_length = json["length"].toInt();
	m_url = json["url"].toString();
	m_user = (json.contains("user")) ? new TelegramUser(json["user"].toObject()) : nullptr;
}

TelegramMessageEntity::TelegramMessageEntity(const TelegramMessageEntity &messageEntity)
{
	m_user = messageEntity.m_user ? new TelegramUser(*messageEntity.m_user) : nullptr;

	m_type = messageEntity.m_type;
	m_offset = messageEntity.m_offset;
	m_length = messageEntity.m_length;
	m_url = messageEntity.m_url;
}

TelegramMessageEntity::~TelegramMessageEntity()
{
	delete m_user;
}

QString TelegramMessageEntity::type() const
{
	return m_type;
}

int TelegramMessageEntity::offset() const
{
	return m_offset;
}

int TelegramMessageEntity::length() const
{
	return m_length;
}

QString TelegramMessageEntity::url() const
{
	return m_url;
}

TelegramUser *TelegramMessageEntity::user() const
{
	return m_user;
}
