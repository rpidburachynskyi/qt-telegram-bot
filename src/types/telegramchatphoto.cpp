#include "telegramchatphoto.h"

TelegramChatPhoto::TelegramChatPhoto(const QJsonObject &json)
	: TelegramBaseTypes(json)
{
	m_smallFileId = json["small_file_id"].toString();
	m_bigFileId = json["big_file_id"].toString();
}

QString TelegramChatPhoto::smallFileId() const
{
    return m_smallFileId;
}

QString TelegramChatPhoto::bigFileId() const
{
    return m_bigFileId;
}
