#ifndef TELEGRAMVOICE_H
#define TELEGRAMVOICE_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramVoice
{
public:
	TelegramVoice(const QJsonObject &json);

	int duration() const;
	QString mimeType() const;
	int fileSize() const;

private:
	int m_duration;
	QString m_mimeType;
	int m_fileSize;
	QString m_fileId;
	TelegramPhotoSize *m_thumb;
};

#endif // TELEGRAMVOICE_H
