#include "telegramanimation.h"

TelegramAnimation::TelegramAnimation(const QJsonObject &json)
	: TelegramBaseTypes(json)
{
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_duration = json["duration"].toInt();

	if(json.contains("file_name")) m_fileName = json["file_name"].toString();
	if(json.contains("mime_type")) m_mimeType = json["mime_type"].toString();
	if(json.contains("file_size")) m_fileSize = json["file_size"].toInt();
	m_fileId = json["file_id"].toString();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
}

TelegramAnimation::TelegramAnimation(const TelegramAnimation &animation)
	: TelegramBaseTypes(false)
{
	m_width = animation.m_width;
	m_height = animation.m_height;
	m_duration = animation.m_duration;
	m_fileName = animation.m_fileName;
	m_mimeType = animation.m_mimeType;
	m_fileSize = animation.m_fileSize;
	m_fileId = animation.m_fileId;

	if(animation.m_thumb) m_thumb = new TelegramPhotoSize(*animation.m_thumb);
	else m_thumb = nullptr;
}

TelegramAnimation::~TelegramAnimation()
{
	if(m_thumb)
		delete m_thumb;
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

TelegramAnimation &TelegramAnimation::operator=(const TelegramAnimation &animation)
{
	delete m_thumb;

	m_width = animation.m_width;
	m_height = animation.m_height;
	m_duration = animation.m_duration;
	m_fileName = animation.m_fileName;
	m_mimeType = animation.m_mimeType;
	m_fileSize = animation.m_fileSize;
	m_fileId = animation.m_fileId;

	if(animation.m_thumb) m_thumb = new TelegramPhotoSize(*animation.m_thumb);
	else m_thumb = nullptr;

	return *this;
}
