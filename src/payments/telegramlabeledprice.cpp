#include "telegramlabeledprice.h"

TelegramLabeledPrice::TelegramLabeledPrice(const QJsonObject &json)
{
	m_label = json["label"].toString();
	m_amount = json["amount"].toInt();
}

QString TelegramLabeledPrice::label() const
{
	return m_label;
}

int TelegramLabeledPrice::amount() const
{
	return m_amount;
}
