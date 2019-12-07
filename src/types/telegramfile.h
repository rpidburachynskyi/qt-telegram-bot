#ifndef TELEGRAMFILE_H
#define TELEGRAMFILE_H

#include "telegrambasetypes.h"

class TelegramFile : public TelegramBaseTypes
{
public:
	TelegramFile(const QJsonObject &json);

	/// Necessarily
	QString fileId() const;
	/// Optional
	int fileSize() const;
	/// Optional
	QString filePath() const;

private:
	QString m_fileId;
	int m_fileSize;
	QString m_filePath;
};

#endif // TELEGRAMFILE_H
