#ifndef TELEGRAMLEFTNEWCHATMEMBER_H
#define TELEGRAMLEFTNEWCHATMEMBER_H

#include <QJsonObject>

class TelegramLeftNewChatMember
{
public:
	TelegramLeftNewChatMember(const QJsonObject &json);

	QString firstName() const;
	QString id() const;
	bool isBot() const;
	QString lastName() const;

private:
	QString m_firstName;
	QString m_id;
	bool m_isBot;
	QString m_lastName;
};

#endif // TELEGRAMNEWCHATMEMBER_H
