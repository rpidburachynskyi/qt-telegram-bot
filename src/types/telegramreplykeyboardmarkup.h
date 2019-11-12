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
								const bool &oneTimeKeyboard = false,
								const bool &selective = false);

	QList<TelegramKeyboardButton> keyboard() const;

	bool resizeKeyboard() const;
	bool oneTimeKeyboard() const;
	bool selective() const;

	QJsonObject toJson() const override;

private:
	QList<TelegramKeyboardButton> m_keyboard;
	bool m_resizeKeyboard;
	bool m_oneTimeKeyboard;
	bool m_selective;
};

#endif // TELEGRAMREPLYKEYBOARDMARKUP_H
