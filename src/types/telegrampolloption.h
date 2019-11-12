#ifndef TELEGRAMPOLLOPTION_H
#define TELEGRAMPOLLOPTION_H

#include <QJsonObject>

class TelegramPollOption
{
public:
	TelegramPollOption(const QJsonObject &json);

	QString text() const;
	int voterCount() const;

private:
	QString m_text;
	int m_voterCount;
};

#endif // TELEGRAMPOLLOPTION_H
