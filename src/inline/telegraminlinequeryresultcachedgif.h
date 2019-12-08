#ifndef TELEGRAMINLINEQUERYRESULTCACHEDGIF_H
#define TELEGRAMINLINEQUERYRESULTCACHEDGIF_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedGif : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedGif(const QString &id,
									   const QString &gifFileId,
									   const QString &title = "",
									   const QString &description = "",
									   const QString &caption = "",
									   const QString &parseMode = "",
									   const TelegramInlineKeyboardMarkup replyMarkup =
			   TelegramInlineKeyboardMarkup(QJsonObject()),
									   const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDGIF_H
