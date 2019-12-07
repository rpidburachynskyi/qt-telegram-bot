#ifndef TELEGRAMINLINEQUERY_H
#define TELEGRAMINLINEQUERY_H

#include "types/telegramuser.h"
#include "types/telegramlocation.h"

class TelegramInlineQuery : public TelegramBaseTypes
{
public:
	TelegramInlineQuery(const QJsonObject &json);

	/// Necessarily
	inline QString id() const {
		return m_id;
	}
	/// Necessarily
	inline TelegramUser from() const {
		return m_from;
	}
	/// Optional
	inline TelegramLocation location() const {
		return m_location;
	}
	/// Necessarily
	inline QString query() const {
		return m_query;
	}
	/// Necessarily
	inline QString offset() const {
		return m_offset;
	}

private:
	QString m_id;
	TelegramUser m_from;
	TelegramLocation m_location;
	QString m_query;
	QString m_offset;
};

#endif // TELEGRAMINLINEQUERY_H
