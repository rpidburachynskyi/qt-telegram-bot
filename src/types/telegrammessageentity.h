#ifndef TELEGRAMMESSAGEENTITY_H
#define TELEGRAMMESSAGEENTITY_H

#include <QJsonObject>

class TelegramUser;

class TelegramMessageEntity
{
public:
	TelegramMessageEntity(const QJsonObject &json);
	TelegramMessageEntity(const TelegramMessageEntity &messageEntity);
	~TelegramMessageEntity();

	/// Necessarily
	QString type() const;
	/// Necessarily
	int offset() const;
	/// Necessarily
	int length() const;
	/// Optional
	QString url() const;
	/// Optional
	TelegramUser *user() const;

	TelegramMessageEntity& operator=(const TelegramMessageEntity &messageEntity) = delete;

private:
	QString m_type;
	int m_offset;
	int m_length;
	QString m_url;
	TelegramUser *m_user;
};

#endif // TELEGRAMMESSAGEENTITY_H
