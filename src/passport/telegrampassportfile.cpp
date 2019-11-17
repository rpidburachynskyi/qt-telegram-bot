#include "telegrampassportfile.h"

TelegramPassportFile::TelegramPassportFile(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_fileSize = json["file_size"].toInt();
	m_fileDate = json["file_date"].toInt();
}

QString TelegramPassportFile::fileId() const
{
	return m_fileId;
}

int TelegramPassportFile::fileSize() const
{
	return m_fileSize;
}

int TelegramPassportFile::fileDate() const
{
	return m_fileDate;
}
