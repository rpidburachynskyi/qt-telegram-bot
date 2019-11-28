#include "telegramprecheckoutquery.h"

TelegramPreCheckoutQuery::TelegramPreCheckoutQuery(const QJsonObject &json)
	: m_user(TelegramUser(json["user"].toObject())),
	  m_orderInfo(TelegramOrderInfo(TelegramOrderInfo(json["order_info"].toObject())))
{
	m_id = json["id"].toString();
	m_currency = json["currency"].toString();
	m_totalAmount = json["total_amount"].toInt();
	m_invoicePayload = json["invoice_payload"].toString();
	m_shippingOptionId = json["shipping_option_id"].toString();
}

QString TelegramPreCheckoutQuery::id() const
{
	return m_id;
}

TelegramUser TelegramPreCheckoutQuery::user() const
{
	return m_user;
}

QString TelegramPreCheckoutQuery::currency() const
{
	return m_currency;
}

int TelegramPreCheckoutQuery::totalAmount() const
{
	return m_totalAmount;
}

QString TelegramPreCheckoutQuery::invoicePayload() const
{
	return m_invoicePayload;
}

QString TelegramPreCheckoutQuery::shippingOptionId() const
{
	return m_shippingOptionId;
}

TelegramOrderInfo TelegramPreCheckoutQuery::orderInfo() const
{
	return m_orderInfo;
}
