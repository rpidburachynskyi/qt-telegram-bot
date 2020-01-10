#ifndef TELEGRAMINLINEBASE_H
#define TELEGRAMINLINEBASE_H

#include "../scripts/telegrambase.h"

class TelegramInlineBase : public TelegramBase
{
public:
	TelegramInlineBase(const QJsonObject &json);
};

#endif // TELEGRAMINLINEBASE_H
