#include "telegraminputmediadocument.h"

TelegramInputMediaDocument::TelegramInputMediaDocument(const QString &media,
													   const QString &caption,
													   const QString &parseMode)
{
	m_media = media;
	m_caption = caption;
	m_parseMode = parseMode;
}

QString TelegramInputMediaDocument::media() const
{
	return m_media;
}

void TelegramInputMediaDocument::setMedia(const QString &media)
{
	m_media = media;
}

QString TelegramInputMediaDocument::caption() const
{
	return m_caption;
}

void TelegramInputMediaDocument::setCaption(const QString &caption)
{
	m_caption = caption;
}

QString TelegramInputMediaDocument::parseMode() const
{
	return m_parseMode;
}

void TelegramInputMediaDocument::setParseMode(const QString &parseMode)
{
	m_parseMode = parseMode;
}

QJsonObject TelegramInputMediaDocument::toJson() const
{
	QJsonObject json;

	json["type"] = "document";
	json["media"] = m_media;
	if(m_caption != "")
		json["caption"] = m_caption;
	if(m_parseMode != "")
		json["parse_mode"] = m_parseMode;

	return json;
}
