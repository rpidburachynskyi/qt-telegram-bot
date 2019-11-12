#include "telegramvideo.h"
#include "telegramphotosize.h"

TelegramVideo::TelegramVideo(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_duration = json["duration"].toInt();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	if(json.contains("thumb")) m_thumb = new TelegramPhotoSize(json["thumb"].toObject());
}

int TelegramVideo::width() const
{
	return m_width;
}

int TelegramVideo::height() const
{
	return m_height;
}

int TelegramVideo::duration() const
{
	return m_duration;
}

QString TelegramVideo::mimeType() const
{
	return m_mimeType;
}

int TelegramVideo::fileSize() const
{
	return m_fileSize;
}

QString TelegramVideo::fileId() const
{
	return m_fileId;
}

TelegramPhotoSize *TelegramVideo::thumb() const
{
	return m_thumb;
}
