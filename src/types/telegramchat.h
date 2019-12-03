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
	TelegramChat (const TelegramChat &chat);
	~TelegramChat();

	/// Necessarily
	QString id() const;
	/// Optinal
	QString type() const;
	/// Optinal
	QString title() const;
	/// Optinal
	QString username() const;
	/// Optinal
	QString firstName() const;
	/// Optinal
	QString lastName() const;
	/// Optinal
	TelegramChatPhoto *photo() const;
	/// Optinal
	QString description() const;
	/// Optinal
	QString inviteLink() const;
	/// Optinal
	TelegramMessage *message() const;
	/// Optinal
	TelegramChatPermissions *chatPermissions() const;
	/// Optinal
	QString stickerSetName() const;
	/// Optinal
	bool canStickerSet() const;

	TelegramChat& operator =(const TelegramChat &chat) = delete;

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
	TelegramMessage *m_message;
	TelegramChatPermissions *m_chatPermissions;
	QString m_stickerSetName;
	bool m_canStickerSet;
};

#endif // TELEGRAMCHAT_H
