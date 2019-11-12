#include "telegramfile.h"

TelegramFile::TelegramFile(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_fileSize = json["file_size"].toInt(-1);
	m_filePath = json["file_path"].toString("");
}

QString TelegramFile::fileId() const
{
	return m_fileId;
}

int TelegramFile::fileSize() const
{
	return m_fileSize;
}

QString TelegramFile::filePath() const
{
	return m_filePath;
}
