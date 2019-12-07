#include "telegrammessageentity.h"

TelegramMessageEntity::TelegramMessageEntity(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_user(json["user"].toObject())
{
	m_type = json["type"].toString();
	m_offset = json["offset"].toInt();
	m_length = json["length"].toInt();
	m_url = json["url"].toString();
}
