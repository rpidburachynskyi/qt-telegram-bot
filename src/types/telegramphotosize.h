#ifndef TELEGRAMPHOTOSIZE_H
#define TELEGRAMPHOTOSIZE_H

#include <QJsonObject>

class TelegramPhotoSize
{
public:
	TelegramPhotoSize(const QJsonObject &json);
	~TelegramPhotoSize();

	QString fileId() const;
	int width() const;
	int height() const;
	int fileSize() const;

private:
	QString m_fileId;
	int m_width;
	int m_height;
	int m_fileSize;
};

#endif // TELEGRAMPHOTOSIZE_H
