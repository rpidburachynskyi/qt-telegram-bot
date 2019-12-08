#ifndef TELEGRAMINLINEQUERYRESULTCACHEDAUDIO_H
#define TELEGRAMINLINEQUERYRESULTCACHEDAUDIO_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedAudio : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedAudio(const QString &id,
										 const QString &audioFileId,
										 const QString &title = "",
										 const QString &description = "",
										 const QString &caption = "",
										 const QString &parseMode = "",
										 const TelegramInlineKeyboardMarkup replyMarkup =
				 TelegramInlineKeyboardMarkup(QJsonObject()),
										 const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDAUDIO_H
