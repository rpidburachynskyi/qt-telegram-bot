#ifndef TELEGRAMINPUTMEDIA_H
#define TELEGRAMINPUTMEDIA_H

#include "telegrambasetypes.h"

class TelegramInputMedia
{
public:
	virtual QJsonObject toJson() const = 0;
};

#endif // TELEGRAMINPUTMEDIA_H
