#include "telegrampolloption.h"

TelegramPollOption::TelegramPollOption(const QJsonObject &json)
{
	m_text = json["text"].toString();
	m_voterCount = json["voter_count"].toInt();
}

QString TelegramPollOption::text() const
{
	return m_text;
}

int TelegramPollOption::voterCount() const
{
	return m_voterCount;
}
