#ifndef TELEGRAMUSERPROFILEPHOTOS_H
#define TELEGRAMUSERPROFILEPHOTOS_H

#include "telegramphotosize.h"
#include <QJsonObject>
#include <QList>

class TelegramUserProfilePhotos
{
public:
	TelegramUserProfilePhotos(const QJsonObject &json);

private:
	int m_totalAmount;
	QList<QList<TelegramPhotoSize>> m_photos;
};

#endif // TELEGRAMUSERPROFILEPHOTOS_H
