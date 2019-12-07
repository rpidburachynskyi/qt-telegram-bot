#ifndef TELEGRAMSHIPPINGQUERY_H
#define TELEGRAMSHIPPINGQUERY_H

#include "types/telegramuser.h"
#include "telegramshippingaddress.h"

class TelegramShippingQuery : public TelegramBasePayments
{
public:
	TelegramShippingQuery(const QJsonObject &json);

	QString id() const;

	TelegramUser user() const;

	QString invoicePayload() const;

	TelegramShippingAddress shippingAddress() const;

private:
	QString m_id;
	TelegramUser m_user;
	QString m_invoicePayload;
	TelegramShippingAddress m_shippingAddress;
};

#endif // TELEGRAMSHIPPINGQUERY_H
