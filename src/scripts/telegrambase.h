#ifndef TELEGRAMBASE_H
#define TELEGRAMBASE_H

#include <QJsonObject>

class TelegramBase
{
public:
	TelegramBase(const QJsonObject &json);

	inline bool isNull() const {
		return m_isNull;
	}
	inline bool isNotNull() const {
		return !m_isNull;
	}

protected:
	bool m_isNull;
};

#endif // TELEGRAMBASE_H
