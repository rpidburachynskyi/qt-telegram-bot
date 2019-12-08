#ifndef TELEGRAMINLINEQUERYRESULTCACHEDDOCUMENT_H
#define TELEGRAMINLINEQUERYRESULTCACHEDDOCUMENT_H

#include "telegraminlinequeryresultcached.h"

class TelegramInlineQueryResultCachedDocument : public TelegramInlineQueryResultCached
{
public:
	TelegramInlineQueryResultCachedDocument(const QString &id,
											const QString &documentFileId,
											const QString &title,
											const QString &description = "",
											const QString &caption = "",
											const QString &parseMode = "",
											const TelegramInlineKeyboardMarkup replyMarkup =
					TelegramInlineKeyboardMarkup(QJsonObject()),
											const TelegramInputMessageContent *inputMessageContent = nullptr);
};

#endif // TELEGRAMINLINEQUERYRESULTCACHEDDOCUMENT_H
