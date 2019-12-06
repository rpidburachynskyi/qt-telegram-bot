#ifndef TELEGRAMINLINEQUERYRESULT_H
#define TELEGRAMINLINEQUERYRESULT_H

#include "scripts/telegrambase.h"
#include "types/telegraminlinekeyboardmarkup.h"

class TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResult();
	virtual ~TelegramInlineQueryResult();
	virtual TelegramInlineQueryResult *clone() const = 0;

	virtual QJsonObject toJson() const = 0;
};

#endif // TELEGRAMINLINEQUERYRESULT_H
