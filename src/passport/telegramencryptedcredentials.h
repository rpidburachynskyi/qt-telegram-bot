#ifndef TELEGRAMENCRYPTEDCREDENTIALS_H
#define TELEGRAMENCRYPTEDCREDENTIALS_H

#include <QJsonObject>

class TelegramEncryptedCredentials
{
public:
	TelegramEncryptedCredentials(const QJsonObject &json);

	/// Necessarily
	QString data() const;
	/// Necessarily
	QString hash() const;
	/// Necessarily
	QString secret() const;

private:
	QString m_data;
	QString m_hash;
	QString m_secret;
};

#endif // TELEGRAMENCRYPTEDCREDENTIALS_H
