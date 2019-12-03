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
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
}

TelegramVideo::TelegramVideo(const TelegramVideo &video)
{
	m_thumb = video.m_thumb ? new TelegramPhotoSize(*video.m_thumb) : nullptr;

	m_fileId = video.m_fileId;
	m_width = video.m_width;
	m_height = video.m_height;
	m_duration = video.m_duration;
	m_mimeType = video.m_mimeType;
	m_fileSize = video.m_fileSize;
}

TelegramVideo::~TelegramVideo()
{
	delete m_thumb;
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
