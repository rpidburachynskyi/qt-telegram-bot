#include "telegramdocument.h"

TelegramDocument::TelegramDocument(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_fileId(json["file_id"].toString()),
	  m_thumb(json["thumb"].toObject()),
	  m_fileName(json["file_name"].toString()),
	  m_mimeType(json["mime_type"].toString()),
	  m_fileSize(json["file_size"].toInt())
{

}

QString TelegramDocument::fileId() const
{
	return m_fileId;
}

TelegramPhotoSize TelegramDocument::thumb() const
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
