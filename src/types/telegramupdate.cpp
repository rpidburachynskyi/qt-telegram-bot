#include "telegramupdate.h"
#include "telegrammessage.h"

#include <QVariant>

TelegramUpdate::TelegramUpdate(const QJsonObject &json)
	: TelegramResult(json),
	  m_message(json["message"].toObject()),
	  m_inlineQuery(json["inline_query"].toObject()),
	  m_chosenInlineResult(json["chosen_inline_result"].toObject()),
	  m_preCheckoutQuery(json["pre_checkout_query"].toObject())
{
	m_updateId = json["update_id"].toVariant().toLongLong( );
}
