#include "telegramvideonote.h"
#include "telegramphotosize.h"

TelegramVideoNote::TelegramVideoNote(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_length = json["length"].toInt();
	m_duration = json["duration"].toInt();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
}

TelegramVideoNote::~TelegramVideoNote()
{
	if(m_thumb)
		delete m_thumb;
}

int TelegramVideoNote::length() const
{
	return m_length;
}

int TelegramVideoNote::duration() const
{
	return m_duration;
}

int TelegramVideoNote::fileSize() const
{
	return m_fileSize;
}

QString TelegramVideoNote::fileId() const
{
	return m_fileId;
}

TelegramPhotoSize *TelegramVideoNote::thumb() const
{
	return m_thumb;
}
