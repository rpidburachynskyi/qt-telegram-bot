#include "telegramaudio.h"

TelegramAudio::TelegramAudio(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_thumb(json["thumb"].toObject())
{
	m_duration = json["duration"].toInt();
	if(json.contains("performer")) m_performer = json["performer"].toString();
	if(json.contains("title")) m_title = json["title"].toString();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_fileId = json["file_id"].toString();
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

TelegramPhotoSize TelegramAudio::thumb() const
{
	return m_thumb;
}

QString TelegramAudio::fileId() const
{
	return m_fileId;
}
