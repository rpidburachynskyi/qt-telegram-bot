#include "telegramanimation.h"
#include "telegramphotosize.h"

TelegramAnimation::TelegramAnimation(const QJsonObject &json)
{
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_duration = json["duration"].toInt();

	if(json.contains("file_name")) m_fileName = json["file_name"].toString();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_fileId = json["file_id"].toString();
	if(json.contains("thumb")) m_thumb = new TelegramPhotoSize(json["thumb"].toObject());
}

int TelegramAnimation::width() const
{
	return m_width;
}

int TelegramAnimation::height() const
{
	return m_height;
}

int TelegramAnimation::duration() const
{
	return m_duration;
}

QString TelegramAnimation::fileName() const
{
	return m_fileName;
}

QString TelegramAnimation::mimeType() const
{
	return m_mimeType;
}

int TelegramAnimation::fileSize() const
{
	return m_fileSize;
}
