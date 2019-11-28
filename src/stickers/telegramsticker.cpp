#include "telegramsticker.h"
#include "types/telegramphotosize.h"
#include "telegrammaskposition.h"

TelegramSticker::TelegramSticker(const QJsonObject &json)
{
	m_fileId = json["file_id"].toString();
	m_width = json["width"].toInt();
	m_height = json["height"].toInt();
	m_isAnimated = json["is_animated"].toBool();
	m_thumb = (json.contains("thumb")) ? new TelegramPhotoSize(json["thumb"].toObject()) : nullptr;
	m_emoji = json["emoji"].toString();
	m_setName = json["set_name"].toString();
	m_maskPosition = (json.contains("mask_position")) ? new TelegramMaskPosition(json["mask_position"].toObject()) : nullptr;
	m_fileSize = json["file_size"].toInt(-1);
}

TelegramSticker::TelegramSticker(const TelegramSticker &sticker)
{
	m_fileId = sticker.m_fileId;
	m_width = sticker.m_width;
	m_height = sticker.m_height;
	m_isAnimated = sticker.m_isAnimated;
	m_emoji = sticker.m_emoji;
	m_setName = sticker.m_setName;
	m_fileSize = sticker.m_fileSize;
	m_thumb = (sticker.m_thumb != nullptr) ? new TelegramPhotoSize(*sticker.m_thumb) : nullptr;
	m_maskPosition = (sticker.m_maskPosition) ? new TelegramMaskPosition(*sticker.m_maskPosition) : nullptr;
}

TelegramSticker::~TelegramSticker()
{
	if(m_thumb)
		delete m_thumb;
	if(m_maskPosition)
		delete m_maskPosition;
}

QString TelegramSticker::fileId() const
{
	return m_fileId;
}

int TelegramSticker::width() const
{
	return m_width;
}

int TelegramSticker::height() const
{
	return m_height;
}

bool TelegramSticker::isAnimated() const
{
	return m_isAnimated;
}

TelegramPhotoSize *TelegramSticker::thumb() const
{
	return m_thumb;
}

QString TelegramSticker::emoji() const
{
	return m_emoji;
}

QString TelegramSticker::setName() const
{
	return m_setName;
}

TelegramMaskPosition *TelegramSticker::maskPosition() const
{
	return m_maskPosition;
}

int TelegramSticker::fileSize() const
{
	return m_fileSize;
}

TelegramSticker &TelegramSticker::operator=(const TelegramSticker &sticker)
{
	if(m_thumb)
		delete m_thumb;
	if(m_maskPosition)
		delete m_maskPosition;

	m_fileId = sticker.m_fileId;
	m_width = sticker.m_width;
	m_height = sticker.m_height;
	m_isAnimated = sticker.m_isAnimated;
	m_emoji = sticker.m_emoji;
	m_setName = sticker.m_setName;
	m_fileSize = sticker.m_fileSize;
	m_thumb = (sticker.m_thumb != nullptr) ? new TelegramPhotoSize(*sticker.m_thumb) : nullptr;
	m_maskPosition = (sticker.m_maskPosition) ? new TelegramMaskPosition(*sticker.m_maskPosition) : nullptr;

	return *this;
}
