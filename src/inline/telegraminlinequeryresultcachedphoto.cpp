#include "telegraminlinequeryresultcachedphoto.h"


TelegramInlineQueryResultCachedPhoto::
TelegramInlineQueryResultCachedPhoto(const QString &id,
									 const QString &photoFileId,
									 const QString &title,
									 const QString &description,
									 const QString &caption,
									 const QString &parseMode,
									 const TelegramInlineKeyboardMarkup replyMarkup,
									 const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Photo,
									  id, photoFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
