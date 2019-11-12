#ifndef TELEGRAMAUDIO_H
#define TELEGRAMAUDIO_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramAudio
{
public:
	TelegramAudio(const QJsonObject &json);

	int duration() const;
	QString performer() const;
	QString title() const;
	QString mimeType() const;
	int fileSize() const;
	TelegramPhotoSize *thumb() const;
	QString fileId() const;

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
