#ifndef TELEGRAMCHOSENINLINERESULT_H
#define TELEGRAMCHOSENINLINERESULT_H

#include "./telegraminlinebase.h"
#include "../types/telegramuser.h"
#include "../types/telegramlocation.h"

class TelegramChosenInlineResult : public TelegramInlineBase
{
public:
	TelegramChosenInlineResult(const QJsonObject &json);

	/// Neccesarily
	QString resultId() const { return m_resultId; }
	/// Neccesarily
	TelegramUser from() const { return m_from; }
	/// Optional
	TelegramLocation location() const { return m_location; }
	/// Optional
	QString inlineMessageId() const { return m_inlineMessageId; }
	/// Neccesarily
	QString query() const { return m_query; }

private:
	QString m_resultId;
	TelegramUser m_from;
	TelegramLocation m_location;
	QString m_inlineMessageId;
	QString m_query;
};

#endif // TELEGRAMCHOSENINLINERESULT_H
