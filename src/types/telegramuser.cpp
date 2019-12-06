#include "telegramuser.h"

#include <QDebug>

TelegramUser::TelegramUser(const QJsonObject &json)
	: TelegramBase(json)
{
	m_id = json["id"].toVariant().toString();
	m_isBot = json["is_bot"].toBool();
	m_firstName = json["first_name"].toString();
	m_username = json["username"].toString();
	m_languageCode = json["language_code"].toString();
}

QString TelegramUser::id() const
{
	return m_id;
}

bool TelegramUser::isBot() const
{
	return m_isBot;
}

QString TelegramUser::firstName() const
{
	return m_firstName;
}

QString TelegramUser::lastName() const
{
	return m_lastName;
}

QString TelegramUser::username() const
{
	return m_username;
}

QString TelegramUser::languageCode() const
{
	return m_languageCode;
}
