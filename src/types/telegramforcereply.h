#ifndef TELEGRAMFORCEREPLY_H
#define TELEGRAMFORCEREPLY_H

#include "itelegrammessagekeyboard.h"

class TelegramInlineKeyboardMarkup;

class TelegramForceReply : public iTelegramMessageKeyboard
{
public:
	TelegramForceReply(const TelegramInlineKeyboardMarkup* keyboard,
					   const bool &selective);
	TelegramForceReply(const TelegramForceReply &forceReply);

	~TelegramForceReply() override;

	QJsonObject toJson() const override;

	TelegramForceReply& operator=(const TelegramForceReply &forceReply) = delete;

	/// Necessarily
	TelegramInlineKeyboardMarkup *keyboard() const;
	/// Optional
	bool selective() const;

private:
	TelegramInlineKeyboardMarkup *m_keyboard;
	bool m_selective;
};

#endif // TELEGRAMFORCEREPLY_H
