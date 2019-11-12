#ifndef TELEGRAMINPUTMEDIAPHOTO_H
#define TELEGRAMINPUTMEDIAPHOTO_H

#include "telegraminputmedia.h"

class TelegramInputMediaPhoto : public TelegramInputMedia
{
public:
	TelegramInputMediaPhoto(const QString &media,
					   const QString &caption = "",
					   const QString &parseMode = "");

	QString media() const;
	void setMedia(const QString &media);

	QString caption() const;
	void setCaption(const QString &caption);

	QString parseMode() const;
	void setParseMode(const QString &parseMode);

public:
	QJsonObject toJson() const override;

private:
	QString m_media;
	QString m_caption;
	QString m_parseMode;
};

#endif // TELEGRAMINPUTMEDIAPHOTO_H
