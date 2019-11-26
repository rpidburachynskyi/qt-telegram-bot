#ifndef TELEGRAMANIMATION_H
#define TELEGRAMANIMATION_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramAnimation
{
public:
	TelegramAnimation(const QJsonObject &json);
	~TelegramAnimation();

	int width() const;
	int height() const;
	int duration() const;
	QString fileName() const;
	QString mimeType() const;
	int fileSize() const;
	TelegramPhotoSize *thumb() const;
	QString fileId() const;

private:
	QString m_fileId;
	int m_width;
	int m_height;
	int m_duration;
	QString m_fileName;
	QString m_mimeType;
	int m_fileSize;
	TelegramPhotoSize *m_thumb;
};

#endif // TELEGRAMANIMATION_H
