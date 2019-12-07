#include "telegramlabeledprice.h"

TelegramLabeledPrice::TelegramLabeledPrice(const QJsonObject &json)
	: TelegramBasePayments(json)
{
	m_label = json["label"].toString();
	m_amount = json["amount"].toInt();
}

TelegramLabeledPrice::TelegramLabeledPrice(const QString &label, const int &amount)
	: TelegramBasePayments(false)
{
	m_label = label;
	m_amount = amount;
}

QString TelegramLabeledPrice::label() const
{
	return m_label;
}

int TelegramLabeledPrice::amount() const
{
	return m_amount;
}

QJsonObject TelegramLabeledPrice::toJson() const
{
	QJsonObject json;

	json["label"] = m_label;
	json["amount"] = m_amount;

	return json;
}
