#ifndef TELEGRAMINPUTCONTACTMESSAGECONTENT_H
#define TELEGRAMINPUTCONTACTMESSAGECONTENT_H

#include "telegraminputmessagecontent.h"

class TelegramInputContactMessageContent : public TelegramInputMessageContent
{
public:
	TelegramInputContactMessageContent(const QString &phoneNumber,
									   const QString &firstName,
									   const QString &lastName = "",
									   const QString &vcard = "");
	TelegramInputMessageContent * clone() const override {
		return new TelegramInputContactMessageContent(*this);
	}

	inline QString phoneNumber() const { return m_phoneNumber; }
	/// Necessarily
	inline void setPhoneNumber(const QString &phoneNumber) { m_phoneNumber = phoneNumber;}

	inline QString firstName() const { return m_firstName; }
	/// Necessarily
	inline void setFirstName(const QString &firstName) { m_firstName = firstName; }

	inline QString lastName() const { return m_lastName; }
	/// Optional
	inline void setLastName(const QString &lastName) { m_lastName = lastName; }

	inline QString vcard() const { return m_vcard; }
	/// Optional
	inline void setVcard(const QString &vcard) { m_vcard = vcard;}

	QJsonObject toJson() const override;

private:
	QString m_phoneNumber;
	QString m_firstName;
	QString m_lastName;
	QString m_vcard;
};

#endif // TELEGRAMINPUTCONTACTMESSAGECONTENT_H
