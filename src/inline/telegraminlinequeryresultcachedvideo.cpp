#include "telegraminlinequeryresultcachedvideo.h"

TelegramInlineQueryResultCachedVideo::
TelegramInlineQueryResultCachedVideo(const QString &id,
									 const QString &videoFileId,
									 const QString &title,
									 const QString &description,
									 const QString &caption,
									 const QString &parseMode,
									 const TelegramInlineKeyboardMarkup replyMarkup,
									 const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Video,
									  id,
									  videoFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
