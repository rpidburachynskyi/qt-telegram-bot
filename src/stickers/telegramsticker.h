#ifndef TELEGRAMSTICKER_H
#define TELEGRAMSTICKER_H

#include <QJsonObject>

class TelegramPhotoSize;
class TelegramMaskPosition;

class TelegramSticker
{
public:
	TelegramSticker(const QJsonObject &json);
	TelegramSticker(const TelegramSticker &sticker);
	~TelegramSticker();

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int width() const;
	/// Necessarily
	int height() const;
	/// Necessarily
	bool isAnimated() const;
	/// Optional
	TelegramPhotoSize *thumb() const;
	/// Optional
	QString emoji() const;
	/// Optional
	QString setName() const;
	/// Optional
	TelegramMaskPosition *maskPosition() const;
	/// Optional
	int fileSize() const;

	TelegramSticker &operator=(const TelegramSticker &sticker);

private:
	QString m_fileId;
	int m_width;
	int m_height;
	bool m_isAnimated;
	TelegramPhotoSize *m_thumb;
	QString m_emoji;
	QString m_setName;
	TelegramMaskPosition *m_maskPosition;
	int m_fileSize;
};

#endif // TELEGRAMSTICKER_H
