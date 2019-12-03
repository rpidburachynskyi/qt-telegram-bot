#include "telegrampassportdata.h"

#include <QJsonArray>

TelegramPassportData::TelegramPassportData(const QJsonObject &json)
{
	m_credentials = new TelegramEncryptedCredentials(json["credentials"].toObject());

	QJsonArray dataArray = json["data"].toArray();

	for(QJsonValueRef dataObject : dataArray)
	{
		auto data = new TelegramEncryptedPassportElement(dataObject.toObject());
		m_data.append(data);
	}
}

TelegramPassportData::TelegramPassportData(const TelegramPassportData &data)
{
	m_credentials = new TelegramEncryptedCredentials(*data.m_credentials);

	for(TelegramEncryptedPassportElement *element : data.m_data)
	{
		auto *newElemnt = new TelegramEncryptedPassportElement(*element);

		m_data.append(newElemnt);
	}
}

TelegramPassportData::~TelegramPassportData()
{
	delete m_credentials;
	for(auto dat : m_data)
	{
		delete dat;
	}
}

QList<TelegramEncryptedPassportElement *> TelegramPassportData::data() const
{
	return m_data;
}

TelegramEncryptedCredentials *TelegramPassportData::credentials() const
{
	return m_credentials;
}
