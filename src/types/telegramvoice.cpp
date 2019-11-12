#include "telegramvoice.h"
#include "telegramphotosize.h"

TelegramVoice::TelegramVoice(const QJsonObject &json)
{
	m_duration = json["duration"].toInt();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_fileId = json["file_id"].toString();
	if(json.contains("thumb")) m_thumb = new TelegramPhotoSize(json["thumb"].toObject());
}

int TelegramVoice::duration() const
{
	return m_duration;
}

QString TelegramVoice::mimeType() const
{
	return m_mimeType;
}

int TelegramVoice::fileSize() const
{
	return m_fileSize;
}
