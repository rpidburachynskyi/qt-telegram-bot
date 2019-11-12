#include "telegramcontact.h"

TelegramContact::TelegramContact(const QJsonObject &json)
{
	m_phoneNumber = json["phone_number"].toString();
	m_firstName = json["first_name"].toString();
	if(json.contains("last_name")) m_lastName = json["last_name"].toString();
	if(json.contains("user_id")) m_userId = json["user_id"].toString();
	if(json.contains("vcard")) m_vcard = json["vcard"].toString();

}

QString TelegramContact::phoneNumber() const
{
	return m_phoneNumber;
}

QString TelegramContact::firstName() const
{
	return m_firstName;
}

QString TelegramContact::lastName() const
{
	return m_lastName;
}

QString TelegramContact::userId() const
{
	return m_userId;
}

QString TelegramContact::vcard() const
{
	return m_vcard;
}
