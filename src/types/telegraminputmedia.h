#ifndef TELEGRAMINPUTMEDIA_H
#define TELEGRAMINPUTMEDIA_H

#include <QJsonObject>

class TelegramInputMedia
{
public:
	virtual QJsonObject toJson() const = 0;
	virtual ~TelegramInputMedia();
};

#endif // TELEGRAMINPUTMEDIA_H
