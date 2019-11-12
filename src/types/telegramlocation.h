#ifndef TELEGRAMLOCATION_H
#define TELEGRAMLOCATION_H

#include <QJsonObject>

class TelegramLocation
{
public:
	TelegramLocation(const QJsonObject &json);

	double longitute() const;
	double latitude() const;

private:
	double m_longitute;
	double m_latitude;
};

#endif // TELEGRAMLOCATION_H
