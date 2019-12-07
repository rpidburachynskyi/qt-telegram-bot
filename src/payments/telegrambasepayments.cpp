#include "telegrambasepayments.h"

TelegramBasePayments::TelegramBasePayments(const bool &isNull)
	: TelegramBase(QJsonObject())
{
	m_isNull = isNull;
}

TelegramBasePayments::TelegramBasePayments(const QJsonObject &json)
	: TelegramBase(json)
{

}
