#include "telegraminputmediaanimation.h"

TelegramInputMediaAnimation::TelegramInputMediaAnimation(const QString &media,
											   const QString &caption)
{
	m_media = media;
	m_caption = caption;
}

QString TelegramInputMediaAnimation::media() const
{
	return m_media;
}

void TelegramInputMediaAnimation::setMedia(const QString &media)
{
	m_media = media;
}

QString TelegramInputMediaAnimation::caption() const
{
	return m_caption;
}

void TelegramInputMediaAnimation::setCaption(const QString &caption)
{
	m_caption = caption;
}

QJsonObject TelegramInputMediaAnimation::toJson() const
{
	QJsonObject json;

	json["type"] = "animation";
	json["media"] = m_media;
	if(m_caption != "")
		json["caption"] = m_caption;

	return json;
}
