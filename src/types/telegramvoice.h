#ifndef TELEGRAMVOICE_H
#define TELEGRAMVOICE_H

#include "telegramphotosize.h"
#include "telegrambasetypes.h"

class TelegramVoice : public TelegramBaseTypes
{
public:
	TelegramVoice(const QJsonObject &json);

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
