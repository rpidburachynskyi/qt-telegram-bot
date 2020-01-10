#ifndef TELEGRAMVENUE_H
#define TELEGRAMVENUE_H

#include "telegramlocation.h"

class TelegramVenue : public TelegramBaseTypes
{
public:
	TelegramVenue(const QJsonObject &json);

	/// Necessarily
	TelegramLocation location() const;
	/// Necessarily
	QString title() const;
	/// Necessarily
	QString address() const;
	/// Optional
	QString foursquareId() const;
	/// Optional
	QString foursquareType() const;

private:
	TelegramLocation m_location;
	QString m_title;
	QString m_address;
	QString m_foursquareId;
	QString m_foursquareType;
};

#endif // TELEGRAMVENUE_H
