#ifndef TELEGRAMMESSAGEENTITY_H
#define TELEGRAMMESSAGEENTITY_H

#include <QJsonObject>

class TelegramUser;

class TelegramMessageEntity
{
public:
	TelegramMessageEntity(const QJsonObject &json);
	~TelegramMessageEntity();

	QString type() const;
	int offset() const;
	int length() const;
	QString url() const;
	TelegramUser *user() const;

private:
	QString m_type;
	int m_offset;
	int m_length;
	QString m_url;
	TelegramUser *m_user;
};

#endif // TELEGRAMMESSAGEENTITY_H
