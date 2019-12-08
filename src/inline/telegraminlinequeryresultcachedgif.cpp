#include "telegraminlinequeryresultcachedgif.h"

TelegramInlineQueryResultCachedGif::
TelegramInlineQueryResultCachedGif(const QString &id,
								   const QString &gifFileId,
								   const QString &title,
								   const QString &description,
								   const QString &caption,
								   const QString &parseMode,
								   const TelegramInlineKeyboardMarkup replyMarkup,
								   const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Gif,
									  id,
									  gifFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
