#include "telegramorderinfo.h"
#include "telegramshippingaddress.h"

TelegramOrderInfo::TelegramOrderInfo(const QJsonObject &json)
{
	m_name = json["name"].toString("");
	m_phoneNumber = json["phone_number"].toString("");
	m_email = json["email"].toString("");
	m_shippingAddress = (json.contains("shipping_address")) ? new TelegramShippingAddress(json["shipping_address"].toObject()) : nullptr;
}

TelegramOrderInfo::~TelegramOrderInfo()
{
	if(m_shippingAddress)
		delete m_shippingAddress;
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

TelegramShippingAddress *TelegramOrderInfo::shippingAddress() const
{
	return m_shippingAddress;
}
