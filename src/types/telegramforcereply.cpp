#include "telegramforcereply.h"
#include "types/telegraminlinekeyboardmarkup.h"

#include <QJsonArray>

TelegramForceReply::TelegramForceReply(const TelegramInlineKeyboardMarkup *keyboard, const bool &selective)
{
	m_keyboard = new TelegramInlineKeyboardMarkup(*keyboard);
	m_selective = selective;
}

QJsonObject TelegramForceReply::toJson() const
{
	QJsonObject json;

	json["keyboard"] = m_keyboard->toJson();
	json["force_reply"] = true;
	json["selective"] = m_selective;

	return json;
}

TelegramForceReply::~TelegramForceReply()
{

}
