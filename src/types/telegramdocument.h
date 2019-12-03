#ifndef TELEGRAMDOCUMENT_H
#define TELEGRAMDOCUMENT_H

#include <QJsonObject>

class TelegramPhotoSize;

class TelegramDocument
{
public:
	TelegramDocument(const QJsonObject &json);
	TelegramDocument(const TelegramDocument &document);
	~TelegramDocument();

	/// Necessarily
	QString fileId() const;
	/// Optional
	TelegramPhotoSize *thumb() const;
	/// Optional
	QString fileName() const;
	/// Optional
	QString mimeType() const;
	/// Optional
	int fileSize() const;

	TelegramDocument &operator=(const TelegramDocument &document) = delete;

private:
	QString m_fileId;
	TelegramPhotoSize *m_thumb;
	QString m_fileName;
	QString m_mimeType;
	int m_fileSize;
};

#endif // TELEGRAMDOCUMENT_H
