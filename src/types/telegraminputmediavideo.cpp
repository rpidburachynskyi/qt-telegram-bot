#include "telegraminputmediavideo.h"

TelegramInputMediaVideo::TelegramInputMediaVideo(const QString &media,
												 const QString &caption,
												 const QString &parseMode)
{
	m_media = media;
	m_caption = caption;
	m_parseMode = parseMode;
}

QString TelegramInputMediaVideo::media() const
{
	return m_media;
}

void TelegramInputMediaVideo::setMedia(const QString &media)
{
	m_media = media;
}

QString TelegramInputMediaVideo::caption() const
{
	return m_caption;
}

void TelegramInputMediaVideo::setCaption(const QString &caption)
{
	m_caption = caption;
}

QString TelegramInputMediaVideo::parseMode() const
{
	return m_parseMode;
}

void TelegramInputMediaVideo::setParseMode(const QString &parseMode)
{
	m_parseMode = parseMode;
}

QJsonObject TelegramInputMediaVideo::toJson() const
{
	QJsonObject json;

	json["type"] = "video";
	json["media"] = m_media;
	if(m_caption != "")
		json["caption"] = m_caption;
	if(m_parseMode != "")
		json["parse_mode"] = m_parseMode;

	return json;
}
