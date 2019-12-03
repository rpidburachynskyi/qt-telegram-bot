#ifndef TELEGRAMREPLYKEYBOARDMARKUP_H
#define TELEGRAMREPLYKEYBOARDMARKUP_H

#include "telegramkeyboardbutton.h"
#include <QList>
#include "itelegrammessagekeyboard.h"


class TelegramReplyKeyboardMarkup : public iTelegramMessageKeyboard
{
public:
	TelegramReplyKeyboardMarkup(const QJsonObject &json);
	TelegramReplyKeyboardMarkup(const QList<TelegramKeyboardButton> &keyboard,
								const bool &resizeKeyboard = false,
								const bool &oneTimeKeyboard = true,
								const bool &selective = false);

	~TelegramReplyKeyboardMarkup() override;

	/// Necessarily
	QList<TelegramKeyboardButton> keyboard() const;
	/// Optional
	bool resizeKeyboard() const;
	/// Optional
	bool oneTimeKeyboard() const;
	/// Optional
	bool selective() const;

	QJsonObject toJson() const override;

private:
	QList<TelegramKeyboardButton> m_keyboard;
	bool m_resizeKeyboard;
	bool m_oneTimeKeyboard;
	bool m_selective;
};

#endif // TELEGRAMREPLYKEYBOARDMARKUP_H
