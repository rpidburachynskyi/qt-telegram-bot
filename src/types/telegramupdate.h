#ifndef TELEGRAMUPDATE_H
#define TELEGRAMUPDATE_H

#include "telegramresult.h"
#include "inline/telegraminlinequery.h"
#include "inline/telegramchoseninlineresult.h"
#include "payments/telegramprecheckoutquery.h"

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
	inline TelegramPreCheckoutQuery preCheckoutQuery() const {
		return m_preCheckoutQuery;
	}
	inline TelegramChosenInlineResult chosenInlineResult() const {
		return m_chosenInlineResult;
	}

	TelegramUpdate& operator=(const TelegramUpdate& update) = delete;

private:
	qint64 m_updateId;
	TelegramMessage *m_message;
	TelegramInlineQuery m_inlineQuery;
	TelegramChosenInlineResult m_chosenInlineResult;
	TelegramPreCheckoutQuery m_preCheckoutQuery;
};

#endif // TELEGRAMUPDATE_H
