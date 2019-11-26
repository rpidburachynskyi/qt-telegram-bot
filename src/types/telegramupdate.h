#ifndef TELEGRAMUPDATE_H
#define TELEGRAMUPDATE_H

#include "telegramresult.h"

#include <QJsonObject>

class TelegramMessage;

class TelegramUpdate : public TelegramResult
{
public:
	TelegramUpdate(const QJsonObject &json);
	~TelegramUpdate();

	QString updateId() const;
	TelegramMessage *message() const;

private:
	QString m_updateId;
	TelegramMessage *m_message;
};

#endif // TELEGRAMUPDATE_H
