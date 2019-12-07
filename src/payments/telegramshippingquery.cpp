#include "telegramshippingquery.h"

TelegramShippingQuery::TelegramShippingQuery(const QJsonObject &json)
	: TelegramBasePayments(json),
	  m_user(TelegramUser(json["user"].toObject())),
	  m_shippingAddress(TelegramShippingAddress(json["shipping_address"].toObject()))
{
	m_id = json["id"].toString();
	m_invoicePayload = json["invoice_payload"].toString();

}

QString TelegramShippingQuery::id() const
{
	return m_id;
}

TelegramUser TelegramShippingQuery::user() const
{
	return m_user;
}

QString TelegramShippingQuery::invoicePayload() const
{
	return m_invoicePayload;
}

TelegramShippingAddress TelegramShippingQuery::shippingAddress() const
{
	return m_shippingAddress;
}
