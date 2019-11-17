#include "telegramencryptedpassportelement.h"
#include "telegrampassportfile.h"

#include <QJsonArray>

TelegramEncryptedPassportElement::TelegramEncryptedPassportElement(const QJsonObject &json)
{
	m_type = json["type"].toString();
	m_data = json["data"].toString();
	m_phoneNumber = json["phone_number"].toString();
	m_email = json["email"].toString();

	m_frontSide = (json.contains("front_side")) ? new TelegramPassportFile(json["front_side"].toObject()) : nullptr;
	m_reverseSide = (json.contains("reverse_side")) ? new TelegramPassportFile(json["reverse_side"].toObject()) : nullptr;
	m_selfie = (json.contains("selfie")) ? new TelegramPassportFile(json["selfie"].toObject()) : nullptr;

	m_hash = json["hash"].toString();

	QJsonArray filesArray = json["files"].toArray();

	for(auto fileObject : filesArray)
	{
		auto file = new TelegramPassportFile(fileObject.toObject());
		m_files.append(file);
	}

	QJsonArray translationArray = json["translation"].toArray();

	for(auto translationObject : translationArray)
	{
		auto file = new TelegramPassportFile(translationObject.toObject());
		m_translation.append(file);
	}
}

QString TelegramEncryptedPassportElement::type() const
{
	return m_type;
}

QString TelegramEncryptedPassportElement::data() const
{
	return m_data;
}

QString TelegramEncryptedPassportElement::phoneNumber() const
{
	return m_phoneNumber;
}

QString TelegramEncryptedPassportElement::email() const
{
	return m_email;
}

QList<const TelegramPassportFile *> TelegramEncryptedPassportElement::files() const
{
	return m_files;
}

TelegramPassportFile *TelegramEncryptedPassportElement::frontSide() const
{
	return m_frontSide;
}

TelegramPassportFile *TelegramEncryptedPassportElement::reverseSide() const
{
	return m_reverseSide;
}

TelegramPassportFile *TelegramEncryptedPassportElement::selfie() const
{
	return m_selfie;
}

QList<const TelegramPassportFile *> TelegramEncryptedPassportElement::translation() const
{
	return m_translation;
}

QString TelegramEncryptedPassportElement::hash() const
{
	return m_hash;
}
