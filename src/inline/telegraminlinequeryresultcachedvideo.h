#ifndef TELEGRAMINLINEQUERYRESULTCACHEDVIDEO_H
#define TELEGRAMINLINEQUERYRESULTCACHEDVIDEO_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedVideo : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedVideo(const QString &id,
										 const QString &videoFileId,
										 const QString &title = "",
										 const QString &description = "",
										 const QString &caption = "",
										 const QString &parseMode = "",
										 const TelegramInlineKeyboardMarkup replyMarkup =
				 TelegramInlineKeyboardMarkup(QJsonObject()),
										 const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDVIDEO_H
