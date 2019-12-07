#ifndef TELEGRAMMESSAGEENTITY_H
#define TELEGRAMMESSAGEENTITY_H

#include "telegramuser.h"

class TelegramMessageEntity  : public TelegramBaseTypes
{
public:
	TelegramMessageEntity(const QJsonObject &json);
	/// Necessarily
	inline const QString &type() const { return m_type; }
	/// Necessarily
	inline const int &offset() const { return m_offset; }
	/// Necessarily
	inline const int &length() const { return m_length; }
	/// Optional
	inline const QString &url() const { return m_url; }
	/// Optional
	inline const TelegramUser &user() const { return m_user; }

private:
	QString m_type;
	int m_offset;
	int m_length;
	QString m_url;
	TelegramUser m_user;
};

#endif // TELEGRAMMESSAGEENTITY_H
