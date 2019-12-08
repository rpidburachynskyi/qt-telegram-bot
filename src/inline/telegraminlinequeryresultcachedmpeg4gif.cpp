#include "telegraminlinequeryresultcachedmpeg4gif.h"

TelegramInlineQueryResultCachedMpeg4Gif::
TelegramInlineQueryResultCachedMpeg4Gif(const QString &id,
										const QString &mpeg4GifFileId,
										const QString &title,
										const QString &description,
										const QString &caption,
										const QString &parseMode,
										const TelegramInlineKeyboardMarkup replyMarkup,
										const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Mpeg4Gif,
									  id,
									  mpeg4GifFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
