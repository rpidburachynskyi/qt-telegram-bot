#include "telegramforcereply.h"
#include "../types/telegraminlinekeyboardmarkup.h"

#include <QJsonArray>

TelegramForceReply::TelegramForceReply(const TelegramInlineKeyboardMarkup *keyboard, const bool &selective)
{
	m_keyboard = new TelegramInlineKeyboardMarkup(*keyboard);
	m_selective = selective;
}

TelegramForceReply::TelegramForceReply(const TelegramForceReply &forceReply)
{
	m_keyboard = forceReply.m_keyboard;
	m_selective = forceReply.m_selective;
}

QJsonObject TelegramForceReply::toJson() const
{
	QJsonObject json;

	json["keyboard"] = m_keyboard->toJson();
	json["force_reply"] = true;
	json["selective"] = m_selective;

	return json;
}

TelegramInlineKeyboardMarkup *TelegramForceReply::keyboard() const
{
	return m_keyboard;
}

bool TelegramForceReply::selective() const
{
	return m_selective;
}

TelegramForceReply::~TelegramForceReply()
{
	delete m_keyboard;
}
