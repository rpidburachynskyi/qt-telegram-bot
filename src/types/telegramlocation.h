#ifndef TELEGRAMLOCATION_H
#define TELEGRAMLOCATION_H

#include "scripts/telegrambase.h"

class TelegramLocation : public TelegramBase
{
public:
	TelegramLocation(const QJsonObject &json);

	/// Necessarily
	double longitute() const;
	/// Necessarily
	double latitude() const;

private:
	double m_longitute;
	double m_latitude;
};

#endif // TELEGRAMLOCATION_H
