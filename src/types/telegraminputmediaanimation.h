#ifndef TELEGRAMINPUTMEDIAANIMATION_H
#define TELEGRAMINPUTMEDIAANIMATION_H

#include "telegraminputmedia.h"

class TelegramInputMediaAnimation : public TelegramInputMedia
{
public:
	TelegramInputMediaAnimation(const QString &media,
					   const QString &caption = "");

	QString media() const;
	void setMedia(const QString &media);

	QString caption() const;
	void setCaption(const QString &caption);

	QJsonObject toJson() const override;

private:
	QString m_media;
	QString m_caption;
};

#endif // TELEGRAMINPUTMEDIAANIMATION_H
