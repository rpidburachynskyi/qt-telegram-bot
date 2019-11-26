#ifndef TELEGRAMORDERINFO_H
#define TELEGRAMORDERINFO_H

#include <QJsonObject>

class TelegramShippingAddress;

class TelegramOrderInfo
{
public:
	TelegramOrderInfo(const QJsonObject &json);
	~TelegramOrderInfo();

	/// Optional
	QString name() const;
	/// Optional
	QString phoneNumber() const;
	/// Optional
	QString email() const;
	/// Optional
	TelegramShippingAddress *shippingAddress() const;

private:
	QString m_name;
	QString m_phoneNumber;
	QString m_email;
	TelegramShippingAddress *m_shippingAddress;
};

#endif // TELEGRAMORDERINFO_H
