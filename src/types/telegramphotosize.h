#ifndef TELEGRAMPHOTOSIZE_H
#define TELEGRAMPHOTOSIZE_H

#include "telegrambasetypes.h"

class TelegramPhotoSize : public TelegramBaseTypes
{
public:
	TelegramPhotoSize(const QJsonObject &json);

	/// Necessarily
	QString fileId() const;
	/// Necessarily
	int width() const;
	/// Necessarily
	int height() const;
	/// Optional
	int fileSize() const;

private:
	QString m_fileId;
	int m_width;
	int m_height;
	int m_fileSize;
};

#endif // TELEGRAMPHOTOSIZE_H
