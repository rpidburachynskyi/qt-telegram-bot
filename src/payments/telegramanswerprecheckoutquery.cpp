#include "telegramanswerprecheckoutquery.h"

TelegramAnswerPreCheckoutQuery::TelegramAnswerPreCheckoutQuery(const QJsonObject &json)
	: TelegramBasePayments(json)
{
	m_preCheckoutQueryId = json["pre_checkout_query_id"].toString();
	m_ok = json["ok"].toBool();
	m_errorMessage = json["error_message"].toString("");
}

QString TelegramAnswerPreCheckoutQuery::preCheckoutQueryId() const
{
	return m_preCheckoutQueryId;
}

bool TelegramAnswerPreCheckoutQuery::ok() const
{
	return m_ok;
}

QString TelegramAnswerPreCheckoutQuery::errorMessage() const
{
	return m_errorMessage;
}
