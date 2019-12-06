#include "telegramupdate.h"
#include "telegrammessage.h"

#include <QVariant>

TelegramUpdate::TelegramUpdate(const QJsonObject &json)
	: TelegramResult(json),
	  m_inlineQuery(json["inline_query"].toObject())
{
	m_updateId = json["update_id"].toVariant().toLongLong( );
	m_message = (json.contains("message")) ? new TelegramMessage(json["message"].toObject()) : nullptr;
}

TelegramUpdate::~TelegramUpdate()
{
	delete m_message;
}

qint64 TelegramUpdate::updateId() const
{
	return m_updateId;
}

TelegramMessage *TelegramUpdate::message() const
{
	return m_message;
}
