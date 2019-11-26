#ifndef TELEGRAMPASSPORTDATA_H
#define TELEGRAMPASSPORTDATA_H

#include "telegramencryptedpassportelement.h"
#include "telegramencryptedcredentials.h"

class TelegramPassportData
{
public:
	TelegramPassportData(const QJsonObject &json);
	~TelegramPassportData();

	/// Necessarily
	QList<TelegramEncryptedPassportElement *> data() const;
	/// Necessarily
	TelegramEncryptedCredentials *credentials() const;

private:
	QList<TelegramEncryptedPassportElement *> m_data;
	TelegramEncryptedCredentials *m_credentials;
};

#endif // TELEGRAMPASSPORTDATA_H
