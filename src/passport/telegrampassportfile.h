#ifndef TELEGRAMPASSPORTFILE_H
#define TELEGRAMPASSPORTFILE_H

#include <QJsonObject>

class TelegramPassportFile
{
public:
	TelegramPassportFile(const QJsonObject &json);

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int fileSize() const;
	/// Necessarily
	int fileDate() const;

private:
	QString m_fileId;
	int m_fileSize;
	int m_fileDate;
};

#endif // TELEGRAMPASSPORTFILE_H
