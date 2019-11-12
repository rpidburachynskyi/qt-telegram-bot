#ifndef TELEGRAMDOCUMENT_H
#define TELEGRAMDOCUMENT_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramDocument
{
public:
	TelegramDocument(const QJsonObject &json);

	QString fileId() const;

	TelegramPhotoSize *thumb() const;

	QString fileName() const;

	QString mimeType() const;

	int fileSize() const;

private:
	QString m_fileId;
	TelegramPhotoSize *m_thumb;
	QString m_fileName;
	QString m_mimeType;
	int m_fileSize;
};

#endif // TELEGRAMDOCUMENT_H
