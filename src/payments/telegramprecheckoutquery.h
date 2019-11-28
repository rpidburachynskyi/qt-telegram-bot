#ifndef TELEGRAMPRECHECKOUTQUERY_H
#define TELEGRAMPRECHECKOUTQUERY_H

#include "telegramorderinfo.h"
#include "types/telegramuser.h"
#include <QJsonObject>

class TelegramPreCheckoutQuery
{
public:
	TelegramPreCheckoutQuery(const QJsonObject &json);

	/// Necessarily
	QString id() const;
	/// Necessarily
	TelegramUser user() const;
	/// Necessarily
	QString currency() const;
	/// Necessarily
	int totalAmount() const;
	/// Necessarily
	QString invoicePayload() const;
	/// Necessarily
	QString shippingOptionId() const;
	/// Necessarily
	TelegramOrderInfo orderInfo() const;

private:
	QString m_id;
	TelegramUser m_user;
	QString m_currency;
	int m_totalAmount;
	QString m_invoicePayload;
	QString m_shippingOptionId;
	TelegramOrderInfo m_orderInfo;
};

#endif // TELEGRAMPRECHECKOUTQUERY_H
