#include "telegrambasesticker.h"

TelegramBaseSticker::TelegramBaseSticker(const bool &isNull)
	: TelegramBase(QJsonObject())
{
	m_isNull = isNull;
}

TelegramBaseSticker::TelegramBaseSticker(const QJsonObject &json)
	: TelegramBase(json)
{ }
