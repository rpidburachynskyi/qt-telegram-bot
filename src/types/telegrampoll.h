#ifndef TELEGRAMPOLL_H
#define TELEGRAMPOLL_H

#include <QList>
#include <QJsonObject>

class TelegramPollOption;

class TelegramPoll
{
public:
	TelegramPoll(const QJsonObject &json);

	QString id() const;
	QString question() const;
	QList<TelegramPollOption *> options() const;
	bool isClosed() const;

private:
	QString m_id;
	QString m_question;
	QList<TelegramPollOption *> m_options;
	bool m_isClosed;
};

#endif // TELEGRAMPOLL_H
