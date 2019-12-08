#include "telegraminlinequeryresultcacheddocument.h"

TelegramInlineQueryResultCachedDocument::
TelegramInlineQueryResultCachedDocument(const QString &id,
										const QString &documentFileId,
										const QString &title,
										const QString &description,
										const QString &caption,
										const QString &parseMode,
										const TelegramInlineKeyboardMarkup replyMarkup,
										const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Document,
									  id,
									  documentFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
