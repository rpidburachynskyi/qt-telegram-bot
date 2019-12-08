#ifndef TELEGRAMINLINEQUERYRESULTCACHEDPHOTO_H
#define TELEGRAMINLINEQUERYRESULTCACHEDPHOTO_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedPhoto : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedPhoto(const QString &id,
										 const QString &photoFileId,
										 const QString &title = "",
										 const QString &description = "",
										 const QString &caption = "",
										 const QString &parseMode = "",
										 const TelegramInlineKeyboardMarkup replyMarkup =
				 TelegramInlineKeyboardMarkup(QJsonObject()),
										 const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDPHOTO_H
