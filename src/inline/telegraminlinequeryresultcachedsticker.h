#ifndef TELEGRAMINLINEQUERYRESULTCACHEDSTICKER_H
#define TELEGRAMINLINEQUERYRESULTCACHEDSTICKER_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedSticker : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedSticker(const QString &id,
										   const QString &stickerFileId,
										   const TelegramInlineKeyboardMarkup replyMarkup =
				   TelegramInlineKeyboardMarkup(QJsonObject()),
										   const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDSTICKER_H
