#ifndef TELEGRAMVIDEO_H
#define TELEGRAMVIDEO_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramVideo
{
public:
	TelegramVideo(const QJsonObject &json);
	~TelegramVideo();

	int width() const;
	int height() const;
	int duration() const;
	QString mimeType() const;
	int fileSize() const;
	QString fileId() const;
	TelegramPhotoSize *thumb() const;

private:
	int m_width;
	int m_height;
	int m_duration;
	QString m_mimeType;
	int m_fileSize;
	QString m_fileId;
	TelegramPhotoSize *m_thumb;
};

#endif // TELEGRAMVIDEO_H
