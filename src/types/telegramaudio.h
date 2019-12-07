#ifndef TELEGRAMAUDIO_H
#define TELEGRAMAUDIO_H

#include "telegramphotosize.h"

class TelegramAudio : public TelegramBaseTypes
{
public:
	TelegramAudio(const QJsonObject &json);

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int duration() const;
	/// Optional
	QString performer() const;
	/// Optional
	QString title() const;
	/// Optional
	QString mimeType() const;
	/// Optional
	int fileSize() const;
	/// Optional
	TelegramPhotoSize thumb() const;

private:
	QString m_fileId;
	int m_duration;
	QString m_performer;
	QString m_title;
	TelegramPhotoSize m_thumb;
	QString m_mimeType;
	int m_fileSize;
};

#endif // TELEGRAMAUDIO_H
