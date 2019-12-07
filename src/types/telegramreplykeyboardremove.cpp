#include "telegramreplykeyboardremove.h"

TelegramReplyKeyboardRemove::TelegramReplyKeyboardRemove(const bool &selective)
	: TelegramBaseTypes(false)
{
	m_selective = true;
}

QJsonObject TelegramReplyKeyboardRemove::toJson() const
{
	QJsonObject json;

	json["remove_keyboard"] = true;
	json["selective"] = m_selective;

	return json;
}

bool TelegramReplyKeyboardRemove::selective() const
{
    return m_selective;
}
