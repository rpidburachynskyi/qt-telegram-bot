#ifndef TELEGRAMUPDATE_H
#define TELEGRAMUPDATE_H

#include "telegramresult.h"
#include "inline/telegraminlinequery.h"

class TelegramMessage;

class TelegramUpdate : public TelegramResult
{
public:
	TelegramUpdate(const QJsonObject &json);
	TelegramUpdate(const TelegramUpdate &update) = delete;
	~TelegramUpdate();

	qint64 updateId() const;
	TelegramMessage *message() const;
	inline TelegramInlineQuery inlineQuery() const {
		return m_inlineQuery;
	}

	TelegramUpdate& operator=(const TelegramUpdate& update) = delete;

private:
	qint64 m_updateId;
	TelegramMessage *m_message;
	TelegramInlineQuery m_inlineQuery;
};

#endif // TELEGRAMUPDATE_H
