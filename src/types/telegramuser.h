#ifndef TELEGRAMUSER_H
#define TELEGRAMUSER_H

#include <QString>
#include <QJsonObject>

class TelegramUser
{
public:
	TelegramUser(const QJsonObject &json);

	QString id() const;
	bool isBot() const;
	QString firstName() const;
	QString lastName() const;
	QString username() const;
	QString languageCode() const;

private:
	QString m_id;
	bool m_isBot;
	QString m_firstName;
	QString m_lastName;
	QString m_username;
	QString m_languageCode;
};

#endif // TELEGRAMUSER_H
