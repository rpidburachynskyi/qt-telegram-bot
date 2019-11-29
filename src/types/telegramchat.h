#ifndef TELEGRAMCHAT_H
#define TELEGRAMCHAT_H

#include <QJsonObject>

class TelegramChatPhoto;
class TelegramMessage;
class TelegramChatPermissions;

class TelegramChat
{
public:
	TelegramChat (const QJsonObject &json);

	QString id() const;
	QString type() const;
	QString title() const;
	QString username() const;

	QString firstName() const;

	QString lastName() const;

	TelegramChatPhoto *photo() const;

private:
	QString m_id;
	QString m_type;
	QString m_title;
	QString m_username;
	QString m_firstName;
	QString m_lastName;
	TelegramChatPhoto *m_photo;
	QString m_description;
	QString m_inviteLink;
	TelegramMessage *m_telegramMessage;
	TelegramChatPermissions *m_telegramChatPermissions;
	QString m_stickerSetName;
	bool m_canStickerSet;
};

#endif // TELEGRAMCHAT_H
