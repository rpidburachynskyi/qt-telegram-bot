#ifndef TELEGRAMBASESTICKER_H
#define TELEGRAMBASESTICKER_H

#include "scripts/telegrambase.h"

class TelegramBaseSticker : public TelegramBase
{
	friend class TelegramSticker;

	TelegramBaseSticker(const bool &isNull);
public:
	TelegramBaseSticker(const QJsonObject &json);
};

#endif // TELEGRAMBASESTICKER_H
