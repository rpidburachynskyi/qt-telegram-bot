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

TelegramEncryptedPassportElement::TelegramEncryptedPassportElement(const TelegramEncryptedPassportElement &element)
{
	m_frontSide = element.m_frontSide ? new TelegramPassportFile(*m_frontSide) : nullptr;
	m_reverseSide = element.m_reverseSide ? new TelegramPassportFile(*m_reverseSide) : nullptr;
	m_selfie = element.m_selfie ? new TelegramPassportFile(*m_selfie) : nullptr;

	for(const TelegramPassportFile *file : element.m_files)
	{
		const TelegramPassportFile *newFile = new const TelegramPassportFile(*file);
		m_files.append(newFile);
	}

	for(const TelegramPassportFile *transl : element.m_translation)
	{
		const TelegramPassportFile *newTransl = new const TelegramPassportFile(*transl);
		m_files.append(newTransl);
	}

	m_type = element.m_type;
	m_data = element.m_data;
	m_phoneNumber = element.m_phoneNumber;
	m_email = element.m_email;
	m_hash = element.m_hash;
}

TelegramEncryptedPassportElement::~TelegramEncryptedPassportElement()
{
	delete m_frontSide;
	delete m_reverseSide;
	delete m_selfie;

	for(auto file : m_files)
	{
		delete file;
	}

	for(auto transl : m_translation)
	{
		delete transl;
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
