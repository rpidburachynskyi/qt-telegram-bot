#ifndef TELEGRAMINPUTVENUEMESSAGECONTENT_H
#define TELEGRAMINPUTVENUEMESSAGECONTENT_H

#include "telegraminputmessagecontent.h"

class TelegramInputVenueMessageContent : public TelegramInputMessageContent
{
public:
	TelegramInputVenueMessageContent(const double &latitude,
									 const double &longitude,
									 const QString &title,
									 const QString &address,
									 const QString &foursquareId = "",
									 const QString &foursquareType = "");

	TelegramInputMessageContent * clone() const override {
		return new TelegramInputVenueMessageContent(*this);
	}

	inline double latitude() const { return m_latitude; }
	/// Necessarily
	inline void setLatitude(double latitude) { m_latitude = latitude; }

	inline double longitude() const { return m_longitude; }
	/// Necessarily
	inline void setLongitude(double longitude) { m_longitude = longitude; }

	inline QString title() const { return m_title; }
	/// Necessarily
	inline void setTitle(const QString &title) { m_title = title; }

	inline QString address() const { return m_address; }
	/// Necessarily
	inline void setAddress(const QString &address) { m_address = address; }

	inline QString foursquareId() const { return m_foursquareId; }
	/// Optional
	inline void setFoursquareId(const QString &foursquareId) { m_foursquareId = foursquareId; }

	inline QString foursquareType() const { return m_foursquareType; }
	/// Optional
	inline void setFoursquareType(const QString &foursquareType) { m_foursquareType = foursquareType; }

	QJsonObject toJson() const override;

private:
	double m_latitude;
	double m_longitude;
	QString m_title;
	QString m_address;
	QString m_foursquareId;
	QString m_foursquareType;
};

#endif // TELEGRAMINPUTVENUEMESSAGECONTENT_H
