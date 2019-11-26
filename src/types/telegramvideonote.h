#ifndef TELEGRAMVIDEONOTE_H
#define TELEGRAMVIDEONOTE_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramVideoNote
{
public:
	TelegramVideoNote(const QJsonObject &json);
	~TelegramVideoNote();

	int length() const;
	int duration() const;
	int fileSize() const;
	QString fileId() const;
	TelegramPhotoSize *thumb() const;

private:
	int m_length;
	int m_duration;
	int m_fileSize;
	QString m_fileId;
	TelegramPhotoSize *m_thumb;
};

#endif // TELEGRAMVIDEONOTE_H
