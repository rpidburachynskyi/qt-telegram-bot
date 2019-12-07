#ifndef TELEGRAMRESULT_H
#define TELEGRAMRESULT_H

#include "telegrambasetypes.h"

class TelegramResult  : public TelegramBaseTypes
{
public:
	TelegramResult(const QJsonObject &json);
};

#endif // TELEGRAMRESULT_H
