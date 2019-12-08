#ifndef TELEGRAMINLINEQUERYRESULTCACHEDVOICE_H
#define TELEGRAMINLINEQUERYRESULTCACHEDVOICE_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedVoice : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedVoice(const QString &id,
										 const QString &voiceFileId,
										 const QString &title = "",
										 const QString &description = "",
										 const QString &caption = "",
										 const QString &parseMode = "",
										 const TelegramInlineKeyboardMarkup replyMarkup =
				 TelegramInlineKeyboardMarkup(QJsonObject()),
										 const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDVOICE_H
