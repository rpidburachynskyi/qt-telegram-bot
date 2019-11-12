#ifndef TELEGRAMCONTACT_H
#define TELEGRAMCONTACT_H

#include <QJsonObject>

class TelegramContact
{
public:
	TelegramContact(const QJsonObject &json);

	QString phoneNumber() const;
	QString firstName() const;
	QString lastName() const;
	QString userId() const;
	QString vcard() const;

private:
	QString m_phoneNumber;
	QString m_firstName;
	QString m_lastName;
	QString m_userId;
	QString m_vcard;
};

#endif // TELEGRAMCONTACT_H
