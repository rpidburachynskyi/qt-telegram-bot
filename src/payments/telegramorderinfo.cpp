#include "telegramorderinfo.h"

TelegramOrderInfo::TelegramOrderInfo(const QJsonObject &json)
	: TelegramBasePayments(json),
	  m_shippingAddress(TelegramShippingAddress(json["shipping_address"].toObject()))
{
	m_name = json["name"].toString("");
	m_phoneNumber = json["phone_number"].toString("");
	m_email = json["email"].toString("");
}

QString TelegramOrderInfo::name() const
{
	return m_name;
}

QString TelegramOrderInfo::phoneNumber() const
{
	return m_phoneNumber;
}

QString TelegramOrderInfo::email() const
{
	return m_email;
}

TelegramShippingAddress TelegramOrderInfo::shippingAddress() const
{
	return m_shippingAddress;
}
