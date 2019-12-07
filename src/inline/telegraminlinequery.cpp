#include "telegraminlinequery.h"

TelegramInlineQuery::TelegramInlineQuery(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_id(json["id"].toString()),
	  m_from(json["from"].toObject()),
	  m_location(json["location"].toObject()),
	  m_query(json["query"].toString()),
	  m_offset(json["query"].toString())
{ }
