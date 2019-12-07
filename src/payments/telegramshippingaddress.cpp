#include "telegramshippingaddress.h"

TelegramShippingAddress::TelegramShippingAddress(const QJsonObject &json)
	: TelegramBasePayments(json)
{
	m_countryCode = json["country_code"].toString();
	m_state = json["state"].toString();
	m_city= json["city"].toString();
	m_streetLine1 = json["street_line1"].toString();
	m_streetLine2 = json["street_line2"].toString();
	m_postCode = json["post_code"].toString();
}

QString TelegramShippingAddress::countryCode() const
{
	return m_countryCode;
}

QString TelegramShippingAddress::state() const
{
	return m_state;
}

QString TelegramShippingAddress::city() const
{
	return m_city;
}

QString TelegramShippingAddress::streetLine1() const
{
	return m_streetLine1;
}

QString TelegramShippingAddress::streetLine2() const
{
	return m_streetLine2;
}

QString TelegramShippingAddress::postCode() const
{
	return m_postCode;
}
