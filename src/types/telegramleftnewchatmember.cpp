#include "telegramleftnewchatmember.h"

TelegramLeftNewChatMember::TelegramLeftNewChatMember(const QJsonObject &json)
{
	m_firstName = json["first_name"].toString("");
	m_id = json["id"].toString("");
	m_isBot = json["is_bot"].toBool();
	m_lastName = json["last_name"].toString("");
}

QString TelegramLeftNewChatMember::firstName() const
{
	return m_firstName;
}

QString TelegramLeftNewChatMember::id() const
{
	return m_id;
}

bool TelegramLeftNewChatMember::isBot() const
{
	return m_isBot;
}

QString TelegramLeftNewChatMember::lastName() const
{
	return m_lastName;
}
