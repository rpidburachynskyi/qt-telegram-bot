#ifndef TELEGRAMUSER_H
#define TELEGRAMUSER_H

#include "scripts/telegrambase.h"

class TelegramUser : public TelegramBase
{
public:
	TelegramUser(const QJsonObject &json);

	/// Necessarily
	QString id() const;
	/// Necessarily
	bool isBot() const;
	/// Necessarily
	QString firstName() const;
	/// Optional
	QString lastName() const;
	/// Optional
	QString username() const;
	/// Optional
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
