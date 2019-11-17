#include "telegraminvoice.h"

TelegramInvoice::TelegramInvoice(const QJsonObject &json)
{
	m_title = json["title"].toString();
	m_description = json["description"].toString();
	m_startParameter = json["start_arameter"].toString();
	m_currency = json["currency"].toString();
	m_totalAmount = json["total_amount"].toInt();
}

QString TelegramInvoice::title() const
{
	return m_title;
}

QString TelegramInvoice::description() const
{
	return m_description;
}

QString TelegramInvoice::startParameter() const
{
	return m_startParameter;
}

QString TelegramInvoice::currency() const
{
	return m_currency;
}

int TelegramInvoice::totalAmount() const
{
	return m_totalAmount;
}
