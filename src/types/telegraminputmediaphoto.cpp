#include "telegraminputmediaphoto.h"

TelegramInputMediaPhoto::TelegramInputMediaPhoto(const QString &media,
									   const QString &caption,
									   const QString &parseMode)
{
	m_media = media;
	m_caption = caption;
	m_parseMode = parseMode;
}

QString TelegramInputMediaPhoto::media() const
{
	return m_media;
}

void TelegramInputMediaPhoto::setMedia(const QString &media)
{
	m_media = media;
}

QString TelegramInputMediaPhoto::caption() const
{
	return m_caption;
}

void TelegramInputMediaPhoto::setCaption(const QString &caption)
{
	m_caption = caption;
}

QString TelegramInputMediaPhoto::parseMode() const
{
	return m_parseMode;
}

void TelegramInputMediaPhoto::setParseMode(const QString &parseMode)
{
	m_parseMode = parseMode;
}


QJsonObject TelegramInputMediaPhoto::toJson() const
{
	QJsonObject json;

	json["type"] = "audio";
	json["media"] = m_media;
	if(m_caption != "")
		json["caption"] = m_caption;
	if(m_parseMode != "")
		json["parse_mode"] = m_parseMode;

	return json;
}
