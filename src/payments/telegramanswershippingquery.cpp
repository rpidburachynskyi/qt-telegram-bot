#include "telegramanswershippingquery.h"

#include <QJsonArray>

TelegramAnswerShippingQuery::TelegramAnswerShippingQuery(const QJsonObject &json)
	: TelegramBasePayments(json)
{
	m_shippingQueryId = json["shipping_query_id"].toString();
	m_ok = json["ok"].toBool();
	m_errorMessage = json["error_message"].toString();

	if(json.contains("shipping_options"))
	{
		QJsonArray array = json["shipping_options"].toArray();

		for(auto item : array)
		{
			TelegramShipingOption option(item.toObject());

			m_options.append(option);
		}
	}
}

QString TelegramAnswerShippingQuery::shippingQueryId() const
{
	return m_shippingQueryId;
}

bool TelegramAnswerShippingQuery::ok() const
{
	return m_ok;
}

QList<TelegramShipingOption> TelegramAnswerShippingQuery::options() const
{
	return m_options;
}

QString TelegramAnswerShippingQuery::errorMessage() const
{
	return m_errorMessage;
}
