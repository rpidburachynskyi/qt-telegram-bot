#include "telegraminputcontactmessagecontent.h"

TelegramInputContactMessageContent::
TelegramInputContactMessageContent(const QString &phoneNumber,
								   const QString &firstName,
								   const QString &lastName,
								   const QString &vcard)
	: m_phoneNumber(phoneNumber),
	  m_firstName(firstName),
	  m_lastName(lastName),
	  m_vcard(vcard)
{ }

QJsonObject TelegramInputContactMessageContent::toJson() const
{
	QJsonObject json;

	json["phone_number"] = m_phoneNumber;
	json["first_name"] = m_firstName;
	if(!m_lastName.isEmpty()) json["last_name"] = m_lastName;
	if(!m_vcard.isEmpty()) json["vcard"] = m_vcard;

	return json;
}
