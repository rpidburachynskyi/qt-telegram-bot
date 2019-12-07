#ifndef TELEGRAMCONTACT_H
#define TELEGRAMCONTACT_H

#include "telegrambasetypes.h"

class TelegramContact : public TelegramBaseTypes
{
public:
	TelegramContact(const QJsonObject &json);

	/// Necessarily
	QString phoneNumber() const;
	/// Necessarily
	QString firstName() const;
	/// Optional
	QString lastName() const;
	/// Optional
	QString userId() const;
	/// Optional
	QString vcard() const;

private:
	QString m_phoneNumber;
	QString m_firstName;
	QString m_lastName;
	QString m_userId;
	QString m_vcard;
};

#endif // TELEGRAMCONTACT_H
