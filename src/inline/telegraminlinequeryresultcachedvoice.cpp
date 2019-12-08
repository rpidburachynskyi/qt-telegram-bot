#include "telegraminlinequeryresultcachedvoice.h"

TelegramInlineQueryResultCachedVoice::
TelegramInlineQueryResultCachedVoice(const QString &id,
									 const QString &voiceFileId,
									 const QString &title,
									 const QString &description,
									 const QString &caption,
									 const QString &parseMode,
									 const TelegramInlineKeyboardMarkup replyMarkup,
									 const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Voice,
									  id,
									  voiceFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
