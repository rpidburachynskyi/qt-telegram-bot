#ifndef TELEGRAMANIMATION_H
#define TELEGRAMANIMATION_H

#include "telegramphotosize.h"

class TelegramAnimation : public TelegramBaseTypes
{
public:
	explicit TelegramAnimation(const QJsonObject &json);
	TelegramAnimation(const TelegramAnimation &animation);
	~TelegramAnimation();

	/// Optional
	QString fileId() const;
	/// Optional
	int width() const;
	/// Optional
	int height() const;
	/// Optional
	int duration() const;
	/// Optional
	TelegramPhotoSize *thumb() const;
	/// Necessarily
	QString fileName() const;
	/// Necessarily
	QString mimeType() const;
	/// Necessarily
	int fileSize() const;

	TelegramAnimation& operator=(const TelegramAnimation &animation);

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
