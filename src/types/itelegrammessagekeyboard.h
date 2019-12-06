#ifndef ITELEGRAMMESSAGEKEYBOARD_H
#define ITELEGRAMMESSAGEKEYBOARD_H

#include <QJsonObject>

class iTelegramMessageKeyboard
{
public:
	virtual QJsonObject toJson() const = 0;
	virtual ~iTelegramMessageKeyboard() { }
};

#endif // ITELEGRAMMESSAGEKEYBOARD_H
