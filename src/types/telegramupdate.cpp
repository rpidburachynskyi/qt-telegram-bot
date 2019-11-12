#include "telegramupdate.h"
#include "telegrammessage.h"

#include <QVariant>

TelegramUpdate::TelegramUpdate(const QJsonObject &json)
	: TelegramResult(json)
{
	m_updateId = json["update_id"].toVariant().toString();
	if(json.contains("message")) m_message = new TelegramMessage(json["message"].toObject());
}

QString TelegramUpdate::updateId() const
{
	return m_updateId;
}

TelegramMessage *TelegramUpdate::message() const
{
	return m_message;
}
