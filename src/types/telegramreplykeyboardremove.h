#ifndef TELEGRAMREPLYKEYBOARDREMOVE_H
#define TELEGRAMREPLYKEYBOARDREMOVE_H

#include "itelegrammessagekeyboard.h"
#include "telegrambasetypes.h"

class TelegramReplyKeyboardRemove : public TelegramBaseTypes, public iTelegramMessageKeyboard
{
public:
	TelegramReplyKeyboardRemove(const bool &selective = false);

	QJsonObject toJson() const;

	/// Optional
	bool selective() const;

private:
	bool m_selective;
};

#endif // TELEGRAMREPLYKEYBOARDREMOVE_H
