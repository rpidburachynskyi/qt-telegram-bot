#ifndef TELEGRAMSTICKERSET_H
#define TELEGRAMSTICKERSET_H

#include "telegramsticker.h"

#include <QJsonObject>
#include <QList>

class TelegramStickerSet
{
public:
	TelegramStickerSet(const QJsonObject &json);

private:
	QString m_name;
	QString m_title;
	bool m_isAnimated;
	bool m_containsMasks;
	QList<TelegramSticker> m_stickers;
};

#endif // TELEGRAMSTICKERSET_H
