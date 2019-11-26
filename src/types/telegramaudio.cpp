#include "telegramaudio.h"
#include "telegramphotosize.h"

TelegramAudio::TelegramAudio(const QJsonObject &json)
{
	m_duration = json["duration"].toInt();
	if(json.contains("performer")) m_performer = json["performer"].toString();
	if(json.contains("title")) m_title = json["title"].toString();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_fileId = json["file_id"].toString();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
}

TelegramAudio::~TelegramAudio()
{
	if(m_thumb)
		delete m_thumb;
}

int TelegramAudio::duration() const
{
	return m_duration;
}

QString TelegramAudio::performer() const
{
	return m_performer;
}

QString TelegramAudio::title() const
{
	return m_title;
}

QString TelegramAudio::mimeType() const
{
	return m_mimeType;
}

int TelegramAudio::fileSize() const
{
	return m_fileSize;
}

TelegramPhotoSize *TelegramAudio::thumb() const
{
	return m_thumb;
}

QString TelegramAudio::fileId() const
{
	return m_fileId;
}
