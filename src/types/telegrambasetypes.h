#ifndef TELEGRAMBASETYPES_H
#define TELEGRAMBASETYPES_H

#include <QJsonObject>

class TelegramBaseTypes
{
	friend class TelegramInlineKeyboardMarkup;
	friend class TelegramChat;
	friend class TelegramAnimation;
	friend class TelegramAudio;
	friend class TelegramVideo;
	friend class TelegramChatPermissions;
	friend class TelegramReplyKeyboardMarkup;
	friend class TelegramReplyKeyboardRemove;

	TelegramBaseTypes(const bool &init);
public:
	TelegramBaseTypes(const QJsonObject &json);

	inline bool isNull() const {
		return m_isNull;
	}
	inline bool isNotNull() const {
		return !m_isNull;
	}
private:
	bool m_isNull;
};

#endif // TELEGRAMBASETYPES_H
