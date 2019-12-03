#ifndef TELEGRAMVOICE_H
#define TELEGRAMVOICE_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramVoice
{
public:
	TelegramVoice(const QJsonObject &json);
	~TelegramVoice();

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int duration() const;
	/// Optional
	QString mimeType() const;
	/// Optional
	int fileSize() const;

private:
	QString m_fileId;
	int m_duration;
	QString m_mimeType;
	int m_fileSize;
};

#endif // TELEGRAMVOICE_H
