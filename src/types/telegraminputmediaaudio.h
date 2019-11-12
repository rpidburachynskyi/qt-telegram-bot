#ifndef TELEGRAMINPUTMEDIAAUDIO_H
#define TELEGRAMINPUTMEDIAAUDIO_H

#include "telegraminputmedia.h"

class TelegramInputMediaAudio : public TelegramInputMedia
{
public:
	TelegramInputMediaAudio(const QString &media,
					   const QString &caption = "");

	QString media() const;
	void setMedia(const QString &media);

	QString caption() const;
	void setCaption(const QString &caption);

	QString parseMode() const;
	void setParseMode(const QString &parseMode);

	QJsonObject toJson() const override;

private:
	QString m_media;
	QString m_caption;
	QString m_parseMode;
};

#endif // TELEGRAMINPUTMEDIAAUDIO_H
