#ifndef TELEGRAMAUDIO_H
#define TELEGRAMAUDIO_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramAudio
{
public:
	TelegramAudio(const QJsonObject &json);
	TelegramAudio(const TelegramAudio &audio);
	~TelegramAudio();

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
	TelegramPhotoSize *thumb() const;

	TelegramAudio& operator=(const TelegramAudio &audio);

private:
	QString m_fileId;
	int m_duration;
	QString m_performer;
	QString m_title;
	TelegramPhotoSize *m_thumb;
	QString m_mimeType;
	int m_fileSize;
};

#endif // TELEGRAMAUDIO_H
