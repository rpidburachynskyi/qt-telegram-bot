#ifndef TELEGRAMSTICKER_H
#define TELEGRAMSTICKER_H

#include <QJsonObject>

class TelegramPhotoSize;
class TelegramMaskPosition;

class TelegramSticker
{
public:
	TelegramSticker(const QJsonObject &json);

	QString fileId() const;
	int width() const;
	int height() const;
	bool isAnimated() const;
	TelegramPhotoSize *thumb() const;
	QString emoji() const;
	QString setName() const;
	TelegramMaskPosition *maskPosition() const;
	int fileSize() const;

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
