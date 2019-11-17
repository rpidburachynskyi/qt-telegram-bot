#include "telegramencryptedcredentials.h"

TelegramEncryptedCredentials::TelegramEncryptedCredentials(const QJsonObject &json)
{
	m_data = json["data"].toString();
	m_hash = json["hash"].toString();
	m_secret = json["secret"].toString();
}

QString TelegramEncryptedCredentials::data() const
{
	return m_data;
}

QString TelegramEncryptedCredentials::hash() const
{
	return m_hash;
}

QString TelegramEncryptedCredentials::secret() const
{
	return m_secret;
}
