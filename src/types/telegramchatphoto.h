#ifndef TELEGRAMCHATPHOTO_H
#define TELEGRAMCHATPHOTO_H

#include <QJsonObject>

class TelegramChatPhoto
{
public:
	TelegramChatPhoto(const QJsonObject &json);

private:
	QString m_smallFileId;
	QString m_bigFileId;
};

#endif // TELEGRAMCHATPHOTO_H
