#include "telegramresponseparameters.h"

TelegramResponseParameters::TelegramResponseParameters(const QJsonObject &json)
{
	m_migrateToChatId = json["migrate_to_chat_id"].toInt();
	m_retryAfter = json["retry_after"].toInt();
}

int TelegramResponseParameters::migrateToChatId() const
{
	return m_migrateToChatId;
}

int TelegramResponseParameters::retryAfter() const
{
	return m_retryAfter;
}
