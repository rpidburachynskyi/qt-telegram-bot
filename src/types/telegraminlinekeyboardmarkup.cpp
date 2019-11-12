#include "telegraminlinekeyboardmarkup.h"

#include <QJsonArray>

TelegramInlineKeyboardMarkup::TelegramInlineKeyboardMarkup(
		const QList<TelegramInlineKeyboardButton> &keyboard)
{
	for(auto button : keyboard)
	{
		TelegramInlineKeyboardButton *newButton = new TelegramInlineKeyboardButton(button);
		m_inlineKeyboard.append(newButton);
	}
}

QList<TelegramInlineKeyboardButton *> TelegramInlineKeyboardMarkup::inlineKeyboard() const
{
	return m_inlineKeyboard;
}

void TelegramInlineKeyboardMarkup::setInlineKeyboard(const QList<TelegramInlineKeyboardButton *> &inlineKeyboard)
{
	m_inlineKeyboard = inlineKeyboard;
}

QJsonObject TelegramInlineKeyboardMarkup::toJson() const
{
	QJsonObject json;

	QJsonArray keyboard;
	for(auto button : m_inlineKeyboard)
	{
		QJsonObject buttonObject = button->toJson();
		QJsonArray array;
		array.append(buttonObject);
		keyboard.append(array);
	}

	json["inline_keyboard"] = keyboard;

	return json;
}

TelegramInlineKeyboardMarkup::~TelegramInlineKeyboardMarkup()
{

}
