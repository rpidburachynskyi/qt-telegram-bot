#include "telegramkeyboardbutton.h"

TelegramKeyboardButton::TelegramKeyboardButton(const QJsonObject &json)
{
	m_text = json["text"].toString();
	m_requestContact = json["request_contact"].toBool(false);
	m_requestLocation = json["request_location"].toBool(false);
}

TelegramKeyboardButton::TelegramKeyboardButton(const QString &text,
											   const bool &requestContact,
											   const bool &requestLocation)
{
	m_text = text;
	m_requestContact = requestContact;
	m_requestLocation = requestLocation;
}

QString TelegramKeyboardButton::text() const
{
	return m_text;
}

bool TelegramKeyboardButton::requestContact() const
{
	return m_requestContact;
}

bool TelegramKeyboardButton::requestLocation() const
{
	return m_requestLocation;
}

QJsonObject TelegramKeyboardButton::toJson() const
{
	QJsonObject json;

	json["text"] = m_text;
	json["request_contact"] = m_requestContact;
	json["request_location"] = m_requestLocation;

	return json;
}
