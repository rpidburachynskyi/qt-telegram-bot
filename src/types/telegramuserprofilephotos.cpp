#include "telegramuserprofilephotos.h"
#include <QJsonArray>

TelegramUserProfilePhotos::TelegramUserProfilePhotos(const QJsonObject &json)
{
	m_totalAmount = json["total_amount"].toInt();

	QJsonArray photosArray = json["photos"].toArray();

	for(QJsonValueRef photoRef : photosArray)
	{
		QJsonArray photoArray = photoRef.toArray();

		QList<TelegramPhotoSize> photoSizes;

		for(QJsonValue photo : photoArray)
		{
			TelegramPhotoSize photoSize(photo.toObject());
			photoSizes.append(photoSize);
		}
		m_photos.append(photoSizes);
	}
}
