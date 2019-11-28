#include "telegramstickerset.h"

#include <QJsonArray>

TelegramStickerSet::TelegramStickerSet(const QJsonObject &json)
{
	m_name = json["name"].toString();
	m_title = json["title"].toString();
	m_isAnimated = json["is_animated"].toBool();
	m_containsMasks = json["contains_masks"].toBool();

	QJsonArray array = json["stickers"].toArray();

	for(auto item : array)
	{
		TelegramSticker sticker(item.toObject());

		m_stickers.append(sticker);
	}
}
