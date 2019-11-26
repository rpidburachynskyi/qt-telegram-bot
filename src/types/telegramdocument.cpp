#include "telegramdocument.h"
#include "telegramphotosize.h"

TelegramDocument::TelegramDocument(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
	if(json.contains("file_name")) m_fileName = json["file_name"].toString();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
}

TelegramDocument::~TelegramDocument()
{
	if(m_thumb)
		delete m_thumb;
}

QString TelegramDocument::fileId() const
{
	return m_fileId;
}

TelegramPhotoSize *TelegramDocument::thumb() const
{
	return m_thumb;
}

QString TelegramDocument::fileName() const
{
	return m_fileName;
}

QString TelegramDocument::mimeType() const
{
	return m_mimeType;
}

int TelegramDocument::fileSize() const
{
	return m_fileSize;
}
