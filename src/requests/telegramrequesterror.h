#ifndef TELEGRAMREQUESTERROR_H
#define TELEGRAMREQUESTERROR_H

#include <QJsonObject>

class TelegramRequestError
{
	TelegramRequestError();

	friend class TelegramRequest;
public:
	TelegramRequestError(const QJsonObject &json);

	int errorCode() const { return m_errorCode; }
	QString description() const { return m_description; }

private:
	int m_errorCode;
	QString m_description;
};

#endif // TELEGRAMREQUESTERROR_H
