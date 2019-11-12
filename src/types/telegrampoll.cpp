#include "telegrampoll.h"
#include "telegrampolloption.h"

#include <QJsonArray>

TelegramPoll::TelegramPoll(const QJsonObject &json)
{
	m_id = json["id"].toString();
	m_question = json["question"].toString();

	m_isClosed = json["is_closed"].toBool();

	QJsonArray options = json["options"].toArray();

	for(auto opt : options)
	{
		TelegramPollOption *option = new TelegramPollOption(opt.toObject());
		m_options.append(option);
	}

}

QString TelegramPoll::id() const
{
	return m_id;
}

QString TelegramPoll::question() const
{
	return m_question;
}

QList<TelegramPollOption *> TelegramPoll::options() const
{
	return m_options;
}

bool TelegramPoll::isClosed() const
{
	return m_isClosed;
}
