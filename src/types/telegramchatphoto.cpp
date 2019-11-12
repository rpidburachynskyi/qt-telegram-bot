#include "telegramchatphoto.h"

TelegramChatPhoto::TelegramChatPhoto(const QJsonObject &json)
{
	m_smallFileId = json["small_file_id"].toString();
	m_bigFileId = json["big_file_id"].toString();
}
