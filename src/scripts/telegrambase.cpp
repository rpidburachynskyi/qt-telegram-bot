#include "telegrambase.h"

TelegramBase::TelegramBase(const QJsonObject &json)
{
	m_isNull = json.isEmpty();
}
