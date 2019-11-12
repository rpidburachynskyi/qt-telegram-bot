#include "telegraminputmediaaudio.h"

TelegramInputMediaAudio::TelegramInputMediaAudio(const QString &media, const QString &caption)
{
	m_media = media;
	m_caption = caption;
}

QString TelegramInputMediaAudio::media() const
{
	return m_media;
}

void TelegramInputMediaAudio::setMedia(const QString &media)
{
	m_media = media;
}

QString TelegramInputMediaAudio::caption() const
{
	return m_caption;
}

void TelegramInputMediaAudio::setCaption(const QString &caption)
{
	m_caption = caption;
}

QString TelegramInputMediaAudio::parseMode() const
{
	return m_parseMode;
}

void TelegramInputMediaAudio::setParseMode(const QString &parseMode)
{
	m_parseMode = parseMode;
}

QJsonObject TelegramInputMediaAudio::toJson() const
{
	QJsonObject json;

	json["type"] = "audio";
	json["media"] = m_media;
	if(m_caption != "")
		json["caption"] = m_caption;

	return json;
}
