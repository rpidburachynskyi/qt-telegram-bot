#include "telegraminlinequeryresultcachedaudio.h"

TelegramInlineQueryResultCachedAudio::
TelegramInlineQueryResultCachedAudio(const QString &id,
									 const QString &audioFileId,
									 const QString &title,
									 const QString &description,
									 const QString &caption,
									 const QString &parseMode,
									 const TelegramInlineKeyboardMarkup replyMarkup,
									 const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Audio,
									  id,
									  audioFileId,
									  title,
									  description,
									  caption,
									  parseMode,
									  replyMarkup,
									  inputMessageContent)
{ }
