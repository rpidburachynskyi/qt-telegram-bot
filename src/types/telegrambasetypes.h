#ifndef TELEGRAMBASETYPES_H
#define TELEGRAMBASETYPES_H

#include <QJsonObject>

class TelegramBaseTypes
{
	friend class TelegramInlineKeyboardMarkup;

	TelegramBaseTypes(const bool &init = false);
public:
	TelegramBaseTypes(const QJsonObject &json);

	inline bool isNull() const {
		return m_isNull;
	}
	inline bool isNotNull() const {
		return !m_isNull;
	}
private:
	bool m_isNull;
};

#endif // TELEGRAMBASETYPES_H
