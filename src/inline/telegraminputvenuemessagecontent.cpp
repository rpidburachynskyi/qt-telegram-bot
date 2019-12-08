#include "telegraminputvenuemessagecontent.h"

TelegramInputVenueMessageContent::
TelegramInputVenueMessageContent(const double &latitude,
								 const double &longitude,
								 const QString &title,
								 const QString &address,
								 const QString &foursquareId,
								 const QString &foursquareType)
	: m_latitude(latitude),
	  m_longitude(longitude),
	  m_title(title),
	  m_address(address),
	  m_foursquareId(foursquareId),
	  m_foursquareType(foursquareType)
{ }

QJsonObject TelegramInputVenueMessageContent::toJson() const
{
	QJsonObject json;

	json["latitue"] = m_latitude;
	json["longitude"] = m_longitude;
	json["title"] = m_title;
	json["address"] = m_address;
	if(!m_foursquareId.isEmpty()) json["foursquare_id"] = m_foursquareId;
	if(!m_foursquareType.isEmpty()) json["foursquare_type"] = m_foursquareType;

	return json;
}
