#ifndef TELEGRAMVENUE_H
#define TELEGRAMVENUE_H

#include <QJsonObject>

class TelegramLocation;

class TelegramVenue
{
public:
	TelegramVenue(const QJsonObject &json);

	TelegramLocation *location() const;
	QString title() const;
	QString address() const;
	QString foursquareId() const;
	QString foursquareType() const;

private:
	TelegramLocation *m_location;
	QString m_title;
	QString m_address;
	QString m_foursquareId;
	QString m_foursquareType;
};

#endif // TELEGRAMVENUE_H
