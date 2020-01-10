#ifndef TELEGRAMUPDATE_H
#define TELEGRAMUPDATE_H

#include "telegramresult.h"
#include "telegrammessage.h"
#include "../inline/telegraminlinequery.h"
#include "../inline/telegramchoseninlineresult.h"
#include "../payments/telegramprecheckoutquery.h"

class TelegramUpdate : public TelegramResult
{
public:
	TelegramUpdate(const QJsonObject &json);

	inline qint64 updateId() const { return m_updateId; }
	inline TelegramMessage message() const { return m_message; }
	inline TelegramInlineQuery inlineQuery() const { return m_inlineQuery; }
	inline TelegramPreCheckoutQuery preCheckoutQuery() const { return m_preCheckoutQuery; }
	inline TelegramChosenInlineResult chosenInlineResult() const { return m_chosenInlineResult; }

	static bool isUpdate(const QJsonObject &json) {
		return json.contains("update_id");
	}

private:
	qint64 m_updateId;
	TelegramMessage m_message;
	TelegramInlineQuery m_inlineQuery;
	TelegramChosenInlineResult m_chosenInlineResult;
	TelegramPreCheckoutQuery m_preCheckoutQuery;
};

#endif // TELEGRAMUPDATE_H
