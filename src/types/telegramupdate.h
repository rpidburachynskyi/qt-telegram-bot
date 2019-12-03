#ifndef TELEGRAMUPDATE_H
#define TELEGRAMUPDATE_H

#include "telegramresult.h"

#include <QJsonObject>

class TelegramMessage;

class TelegramUpdate : public TelegramResult
{
public:
	TelegramUpdate(const QJsonObject &json);
	TelegramUpdate(const TelegramUpdate &update) = delete;
	~TelegramUpdate();

	QString updateId() const;
	TelegramMessage *message() const;

	TelegramUpdate& operator=(const TelegramUpdate& update) = delete;

private:
	QString m_updateId;
	TelegramMessage *m_message;
};

#endif // TELEGRAMUPDATE_H
