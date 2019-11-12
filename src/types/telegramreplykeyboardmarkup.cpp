#include "telegramreplykeyboardmarkup.h"

#include <QJsonArray>
#include "telegramkeyboardbutton.h"

TelegramReplyKeyboardMarkup::TelegramReplyKeyboardMarkup(const QJsonObject &json)
{
	QJsonArray keyboard = json["keyboard"].toArray();
	for(auto key : keyboard)
	{
		TelegramKeyboardButton button (key.toObject());
		m_keyboard.append(button);
	}

	m_resizeKeyboard = json["resize_keyboard"].toBool(false);
	m_oneTimeKeyboard = json["one_time_keyboard"].toBool(false);
	m_selective = json["selective"].toBool(false);
}

TelegramReplyKeyboardMarkup::TelegramReplyKeyboardMarkup(const QList<TelegramKeyboardButton> &keyboard,
														 const bool &resizeKeyboard,
														 const bool &oneTimeKeyboard,
														 const bool &selective)
{
	m_keyboard = keyboard;
	m_resizeKeyboard = resizeKeyboard;
	m_oneTimeKeyboard = oneTimeKeyboard;
	m_selective = selective;
}

QList<TelegramKeyboardButton> TelegramReplyKeyboardMarkup::keyboard() const
{
	return m_keyboard;
}

bool TelegramReplyKeyboardMarkup::resizeKeyboard() const
{
	return m_resizeKeyboard;
}

bool TelegramReplyKeyboardMarkup::oneTimeKeyboard() const
{
	return m_oneTimeKeyboard;
}

bool TelegramReplyKeyboardMarkup::selective() const
{
	return m_selective;
}

QJsonObject TelegramReplyKeyboardMarkup::toJson() const
{
	QJsonObject json;

	QJsonArray rootKeys;
	QJsonArray keys;
	for(auto key : m_keyboard)
	{
		keys.append(key.toJson());
	}

	rootKeys.append(keys);

	json["keyboard"] = rootKeys;
	json["resize_keyboard"] = m_resizeKeyboard;
	json["one_time_keyboard"] = m_oneTimeKeyboard;
	json["selective"] = m_selective;

	return json;
}
