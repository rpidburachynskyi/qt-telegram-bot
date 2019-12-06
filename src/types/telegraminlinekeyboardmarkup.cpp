#include "telegraminlinekeyboardmarkup.h"

#include <QJsonArray>

TelegramInlineKeyboardMarkup::TelegramInlineKeyboardMarkup(const QJsonObject &json)
	: TelegramBaseTypes(json)
{
	QJsonArray arrayButtons = json["inline_keyboard"].toArray();

	for(QJsonValueRef arrayButton : arrayButtons)
	{
		TelegramInlineKeyboardButton button(arrayButton.toObject());

		m_inlineKeyboard.append(button);
	}
}

TelegramInlineKeyboardMarkup::TelegramInlineKeyboardMarkup(
		const QList<TelegramInlineKeyboardButton> &keyboard)
	: TelegramBaseTypes(true)
{
	m_inlineKeyboard = keyboard;
}

QList<TelegramInlineKeyboardButton> TelegramInlineKeyboardMarkup::inlineKeyboard() const
{
	return m_inlineKeyboard;
}

void TelegramInlineKeyboardMarkup::setInlineKeyboard(const QList<TelegramInlineKeyboardButton> &inlineKeyboard)
{
	m_inlineKeyboard = inlineKeyboard;
}

QJsonObject TelegramInlineKeyboardMarkup::toJson() const
{
	QJsonObject json;

	QJsonArray keyboard;
	for(auto button : m_inlineKeyboard)
	{
		QJsonObject buttonObject = button.toJson();
		QJsonArray array;
		array.append(buttonObject);
		keyboard.append(array);
	}

	json["inline_keyboard"] = keyboard;
	return json;
}
