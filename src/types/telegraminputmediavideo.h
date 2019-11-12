#ifndef TELEGRAMINPUTMEDIAVIDEO_H
#define TELEGRAMINPUTMEDIAVIDEO_H

#include "telegraminputmedia.h"

class TelegramInputMediaVideo : public TelegramInputMedia
{
public:
	TelegramInputMediaVideo(const QString &media,
							const QString &caption = "",
							const QString &parseMode = "");

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

#endif // TELEGRAMINPUTMEDIAVIDEO_H
