#ifndef TELEGRAMPOLL_H
#define TELEGRAMPOLL_H

#include <QList>
#include <QJsonObject>

class TelegramPollOption;

class TelegramPoll
{
public:
	TelegramPoll(const QJsonObject &json);
	TelegramPoll(const TelegramPoll &poll);
	~TelegramPoll();

	/// Necessarily
	QString id() const;
	/// Necessarily
	QString question() const;
	/// Necessarily
	QList<TelegramPollOption *> options() const;
	/// Necessarily
	bool isClosed() const;

	TelegramPoll& operator=(const TelegramPoll &poll) = delete;

private:
	QString m_id;
	QString m_question;
	QList<TelegramPollOption *> m_options;
	bool m_isClosed;
};

#endif // TELEGRAMPOLL_H
