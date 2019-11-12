#ifndef TELEGRAMFORCEREPLY_H
#define TELEGRAMFORCEREPLY_H

#include "itelegrammessagekeyboard.h"

class TelegramInlineKeyboardMarkup;

class TelegramForceReply : public iTelegramMessageKeyboard
{
public:
	TelegramForceReply(const TelegramInlineKeyboardMarkup* keyboard,
					   const bool &selective);

	QJsonObject toJson() const override;

	~TelegramForceReply() override;

private:
	TelegramInlineKeyboardMarkup *m_keyboard;
	bool m_selective;
};

#endif // TELEGRAMFORCEREPLY_H
