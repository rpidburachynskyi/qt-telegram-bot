#ifndef TELEGRAMORDERINFO_H
#define TELEGRAMORDERINFO_H

#include "telegramshippingaddress.h"

class TelegramOrderInfo : public TelegramBasePayments
{
public:
	TelegramOrderInfo(const QJsonObject &json);

	/// Optional
	QString name() const;
	/// Optional
	QString phoneNumber() const;
	/// Optional
	QString email() const;
	/// Optional
	TelegramShippingAddress shippingAddress() const;

private:
	QString m_name;
	QString m_phoneNumber;
	QString m_email;
	TelegramShippingAddress m_shippingAddress;
};

#endif // TELEGRAMORDERINFO_H
