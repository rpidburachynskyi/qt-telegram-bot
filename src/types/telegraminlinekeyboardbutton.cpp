#include "telegraminlinekeyboardbutton.h"

TelegramInlineKeyboardButton::TelegramInlineKeyboardButton(const QString &text)
{
	m_text = text;
}

QString TelegramInlineKeyboardButton::text() const
{
	return m_text;
}

void TelegramInlineKeyboardButton::setText(const QString &text)
{
	m_text = text;
}

QString TelegramInlineKeyboardButton::url() const
{
	return m_url;
}

void TelegramInlineKeyboardButton::setUrl(const QString &url)
{
	m_url = url;
}

TelegramLoginUrl *TelegramInlineKeyboardButton::loginUrl() const
{
	return m_loginUrl;
}

void TelegramInlineKeyboardButton::setLoginUrl(TelegramLoginUrl *loginUrl)
{
	m_loginUrl = loginUrl;
}

QString TelegramInlineKeyboardButton::callbackData() const
{
	return m_callbackData;
}

void TelegramInlineKeyboardButton::setCallbackData(const QString &callbackData)
{
	m_callbackData = callbackData;
}

QString TelegramInlineKeyboardButton::switchInlineQuery() const
{
	return m_switchInlineQuery;
}

void TelegramInlineKeyboardButton::setSwitchInlineQuery(const QString &switchInlineQuery)
{
	m_switchInlineQuery = switchInlineQuery;
}

QString TelegramInlineKeyboardButton::switchInlineQueryCurrentChat() const
{
	return m_switchInlineQueryCurrentChat;
}

void TelegramInlineKeyboardButton::setSwitchInlineQueryCurrentChat(const QString &switchInlineQueryCurrentChat)
{
	m_switchInlineQueryCurrentChat = switchInlineQueryCurrentChat;
}

bool TelegramInlineKeyboardButton::pay() const
{
	return m_pay;
}

void TelegramInlineKeyboardButton::setPay(bool pay)
{
	m_pay = pay;
}

QJsonObject TelegramInlineKeyboardButton::toJson() const
{
	QJsonObject json;

	json["text"] = m_text;
	json["url"] = "https://google.com.ua";

	return json;
}
