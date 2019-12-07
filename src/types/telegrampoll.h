#ifndef TELEGRAMPOLL_H
#define TELEGRAMPOLL_H

#include "telegrampolloption.h"
#include <QList>

class TelegramPoll : public TelegramBaseTypes
{
public:
	TelegramPoll(const QJsonObject &json);

	/// Necessarily
	QString id() const;
	/// Necessarily
	QString question() const;
	/// Necessarily
	QList<TelegramPollOption> options() const;
	/// Necessarily
	bool isClosed() const;

private:
	QString m_id;
	QString m_question;
	QList<TelegramPollOption> m_options;
	bool m_isClosed;
};

#endif // TELEGRAMPOLL_H
