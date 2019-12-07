#ifndef TELEGRAMVIDEO_H
#define TELEGRAMVIDEO_H

#include "telegramphotosize.h"

class TelegramVideo : public TelegramBaseTypes
{
public:
	TelegramVideo(const QJsonObject &json);

	QString fileId() const;
	/// Necessarily
	/// Necessarily
	int width() const;
	/// Necessarily
	int height() const;
	/// Necessarily
	int duration() const;
	/// Optional
	TelegramPhotoSize thumb() const;
	/// Optional
	QString mimeType() const;
	/// Optional
	int fileSize() const;

private:
	int m_width;
	int m_height;
	int m_duration;
	QString m_mimeType;
	int m_fileSize;
	QString m_fileId;
	TelegramPhotoSize m_thumb;
};

#endif // TELEGRAMVIDEO_H
