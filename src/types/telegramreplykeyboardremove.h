#ifndef TELEGRAMREPLYKEYBOARDREMOVE_H
#define TELEGRAMREPLYKEYBOARDREMOVE_H

#include "itelegrammessagekeyboard.h"

#include <QJsonObject>

class TelegramReplyKeyboardRemove : public iTelegramMessageKeyboard
{
public:
	TelegramReplyKeyboardRemove(const bool &selective = false);

	QJsonObject toJson() const;

private:
	bool m_selective;
};

#endif // TELEGRAMREPLYKEYBOARDREMOVE_H
