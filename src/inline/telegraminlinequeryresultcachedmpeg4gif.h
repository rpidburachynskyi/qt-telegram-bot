#ifndef TELEGRAMINLINEQUERYRESULTCACHEDMPEG4GIF_H
#define TELEGRAMINLINEQUERYRESULTCACHEDMPEG4GIF_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedMpeg4Gif : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedMpeg4Gif(const QString &id,
											const QString &mpeg4GifFileId,
											const QString &title = "",
											const QString &description = "",
											const QString &caption = "",
											const QString &parseMode = "",
											const TelegramInlineKeyboardMarkup replyMarkup =
					TelegramInlineKeyboardMarkup(QJsonObject()),
											const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDMPEG4GIF_H
