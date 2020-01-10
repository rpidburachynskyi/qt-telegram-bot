#ifndef TELEGRAMSTICKER_H
#define TELEGRAMSTICKER_H

#include "telegrammaskposition.h"
#include "../types/telegramphotosize.h"
#include "telegrambasesticker.h"

class TelegramSticker : public TelegramBaseSticker
{
public:
	TelegramSticker(const QJsonObject &json);

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int width() const;
	/// Necessarily
	int height() const;
	/// Necessarily
	bool isAnimated() const;
	/// Optional
	TelegramPhotoSize thumb() const;
	/// Optional
	QString emoji() const;
	/// Optional
	QString setName() const;
	/// Optional
	TelegramMaskPosition maskPosition() const;
	/// Optional
	int fileSize() const;

private:
	QString m_fileId;
	int m_width;
	int m_height;
	bool m_isAnimated;
	TelegramPhotoSize m_thumb;
	QString m_emoji;
	QString m_setName;
	TelegramMaskPosition m_maskPosition;
	int m_fileSize;
};

#endif // TELEGRAMSTICKER_H
