#ifndef TELEGRAMRESPONSEPARAMETERS_H
#define TELEGRAMRESPONSEPARAMETERS_H

#include <QJsonObject>

class TelegramResponseParameters
{
public:
	TelegramResponseParameters(const QJsonObject &json);

	int migrateToChatId() const;

	int retryAfter() const;

private:
	int m_migrateToChatId;
	int m_retryAfter;
};

#endif // TELEGRAMRESPONSEPARAMETERS_H
