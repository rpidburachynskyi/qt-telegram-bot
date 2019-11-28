#include "telegramshipingoption.h"

#include <QJsonArray>

TelegramShipingOption::TelegramShipingOption(const QJsonObject &json)
{
	m_id = json["id"].toString();
	m_title = json["title"].toString();


	QJsonArray array = json["prices"].toArray();

	for(auto item : array)
	{
		TelegramLabeledPrice price(item.toObject());

		m_prices.append(price);
	}
}

QString TelegramShipingOption::id() const
{
	return m_id;
}

void TelegramShipingOption::setId(const QString &id)
{
	m_id = id;
}

QString TelegramShipingOption::title() const
{
	return m_title;
}

void TelegramShipingOption::setTitle(const QString &title)
{
	m_title = title;
}

QList<TelegramLabeledPrice> TelegramShipingOption::prices() const
{
	return m_prices;
}

void TelegramShipingOption::setPrices(const QList<TelegramLabeledPrice> &prices)
{
	m_prices = prices;
}
