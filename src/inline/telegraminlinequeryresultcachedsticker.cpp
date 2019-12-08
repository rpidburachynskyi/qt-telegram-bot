#include "telegraminlinequeryresultcachedsticker.h"

TelegramInlineQueryResultCachedSticker::
TelegramInlineQueryResultCachedSticker(const QString &id,
									   const QString &stickerFileId,
									   const TelegramInlineKeyboardMarkup replyMarkup,
									   const TelegramInputMessageContent *inputMessageContent)
	: TelegramInlineQueryResultCached(TelegramInlineQueryResultCached::Sticker,
									  id,
									  stickerFileId,
									  "",
									  "",
									  "",
									  "",
									  replyMarkup,
									  inputMessageContent)
{ }
