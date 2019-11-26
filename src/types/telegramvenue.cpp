#include "telegramvenue.h"
#include "telegramlocation.h"

TelegramVenue::TelegramVenue(const QJsonObject &json)
{
	m_location = new TelegramLocation(json["location"].toObject());
	m_title = json["title"].toString();
	m_address = json["title"].toString();
	if(json.contains("foursquare_id")) m_foursquareId = json["foursquare_id"].toString();
	if(json.contains("foursquare_type")) m_foursquareType = json["foursquare_type"].toString();
}

TelegramVenue::~TelegramVenue()
{
	if(m_location)
		delete m_location;
}

TelegramLocation *TelegramVenue::location() const
{
	return m_location;
}

QString TelegramVenue::title() const
{
	return m_title;
}

QString TelegramVenue::address() const
{
	return m_address;
}

QString TelegramVenue::foursquareId() const
{
	return m_foursquareId;
}

QString TelegramVenue::foursquareType() const
{
	return m_foursquareType;
}
