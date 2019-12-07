#ifndef TELEGRAMCHATPHOTO_H
#define TELEGRAMCHATPHOTO_H

#include "telegrambasetypes.h"

class TelegramChatPhoto : public TelegramBaseTypes
{
public:
	TelegramChatPhoto(const QJsonObject &json);

	// Necessarily
	QString smallFileId() const;
	// Necessarily
	QString bigFileId() const;

private:
	QString m_smallFileId;
	QString m_bigFileId;
};

#endif // TELEGRAMCHATPHOTO_H
