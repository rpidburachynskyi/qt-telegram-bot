#include "telegramphotosize.h"
#include <QDebug>

TelegramPhotoSize::TelegramPhotoSize(const QJsonObject &json)
	: TelegramBaseTypes(json)
{
	m_fileId = json["file_id"].toString();
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_fileSize = json["file_size"].toInt();
}

QString TelegramPhotoSize::fileId() const
{
	return m_fileId;
}

int TelegramPhotoSize::width() const
{
	return m_width;
}

int TelegramPhotoSize::height() const
{
	return m_height;
}

int TelegramPhotoSize::fileSize() const
{
	return m_fileSize;
}
