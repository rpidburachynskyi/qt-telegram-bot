#ifndef TELEGRAMCHATPHOTO_H
#define TELEGRAMCHATPHOTO_H

#include <QJsonObject>

class TelegramChatPhoto
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
