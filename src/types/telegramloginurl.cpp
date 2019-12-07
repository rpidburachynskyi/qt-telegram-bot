#include "telegramloginurl.h"

TelegramLoginUrl::TelegramLoginUrl(const QJsonObject &json)
	: TelegramBaseTypes(json)
{
	m_url = json["url"].toString();
	m_forwardText = json["forward_text"].toString();
	m_botUsername = json["bot_username"].toString();
	m_requestWriteAccess = json["request_write_access"].toBool();
}

QString TelegramLoginUrl::url() const
{
	return m_url;
}

QString TelegramLoginUrl::forwardText() const
{
	return m_forwardText;
}

QString TelegramLoginUrl::botUsername() const
{
	return m_botUsername;
}

bool TelegramLoginUrl::requestWriteAccess() const
{
	return m_requestWriteAccess;
}

QJsonObject TelegramLoginUrl::toJson() const
{
	QJsonObject json;

	json["url"] = m_url;
	json["forward_text"] = m_forwardText;
	json["bot_username"] = m_botUsername;
	json["request_write_access"] = m_requestWriteAccess;

	return json;
}
