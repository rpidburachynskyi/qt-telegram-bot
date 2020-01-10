#ifndef TELEGRAMBASESTICKER_H
#define TELEGRAMBASESTICKER_H

<<<<<<< HEAD
#include "../scripts/telegrambase.h"
=======
#include "scripts/telegrambase.h"
>>>>>>> 211af8f699f88e51a584b62298f2b6cd3721154e

class TelegramBaseSticker : public TelegramBase
{
	friend class TelegramSticker;

	TelegramBaseSticker(const bool &isNull);
public:
	TelegramBaseSticker(const QJsonObject &json);
};

#endif // TELEGRAMBASESTICKER_H
