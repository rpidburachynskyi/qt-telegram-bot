#include "telegramlocation.h"

TelegramLocation::TelegramLocation(const QJsonObject &json)
	: TelegramBase(json)
{
	m_longitute = json["longitude"].toDouble();
	m_latitude = json["latitude"].toDouble();
}

double TelegramLocation::longitute() const
{
	return m_longitute;
}

double TelegramLocation::latitude() const
{
	return m_latitude;
}
