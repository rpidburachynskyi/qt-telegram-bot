#include "telegrambasetypes.h"

TelegramBaseTypes::TelegramBaseTypes(const bool &init)
{
	m_isNull = !init;
}

TelegramBaseTypes::TelegramBaseTypes(const QJsonObject &json)
{
	m_isNull = json.isEmpty();
}
