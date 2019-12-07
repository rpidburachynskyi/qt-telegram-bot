#include "telegramchoseninlineresult.h"

TelegramChosenInlineResult::TelegramChosenInlineResult(const QJsonObject &json)
	: TelegramInlineBase(json),
	  m_resultId(json["result_id"].toString()),
	  m_from(json["from"].toObject()),
	  m_location(json["location"].toObject()),
	  m_inlineMessageId(json["inline_message_id"].toString()),
	  m_query(json["query"].toString())
{ }
