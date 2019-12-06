#ifndef TELEGRAMINPUTMESSAGECONTENT_H
#define TELEGRAMINPUTMESSAGECONTENT_H

#include "scripts/telegrambase.h"

class TelegramInputMessageContent
{
public:
	TelegramInputMessageContent();
	virtual ~TelegramInputMessageContent();
	virtual TelegramInputMessageContent* clone() const = 0;
	virtual QJsonObject toJson() const = 0;
};

#endif // TELEGRAMINPUTMESSAGECONTENT_H
