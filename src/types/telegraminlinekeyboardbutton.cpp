#include "telegraminlinekeyboardbutton.h"
#include "telegramloginurl.h"
#include <QtDebug>
TelegramInlineKeyboardButton::TelegramInlineKeyboardButton(const QJsonObject &json)
{
	m_text = json["text"].toString();
	m_url = json["url"].toString();
	m_loginUrl = json.contains("login_url") ? new TelegramLoginUrl(json["login_url"].toObject()) : nullptr;
	m_callbackData = json["callback_data"].toString();
	m_switchInlineQuery = json["switch_inline_query"].toString();
	m_switchInlineQueryCurrentChat = json["switch_inline_query_current_chat"].toString();
	//m_callbackGame = json["text"].toString();
	m_pay = json["pay"].toBool();
}

TelegramInlineKeyboardButton::TelegramInlineKeyboardButton(const QString &text,
														   const QString &url,
														   const TelegramLoginUrl *loginUrl,
														   const QString &callbackData,
														   const QString &switchInlineQuery,
														   const QString &switchInlineQueryCurrentChat,
														   const TelegramCallbackGame *callbackGame,
														   const bool &pay)
{
	m_text = text;
	m_url = url;
	m_loginUrl = loginUrl ? new TelegramLoginUrl(*loginUrl) : nullptr;
	m_callbackData = callbackData;
	m_switchInlineQuery = switchInlineQuery;
	m_switchInlineQueryCurrentChat = switchInlineQueryCurrentChat;
	//m_callbackGame = callbackGame ? new TelegramCallbackGame(*callbackGame) : nullptr; FIXIT
	m_pay = pay;
}

TelegramInlineKeyboardButton::TelegramInlineKeyboardButton(const TelegramInlineKeyboardButton &button)
{
	m_text = button.m_text;
	m_url = button.m_url;
	m_loginUrl = button.m_loginUrl ? new TelegramLoginUrl(*button.m_loginUrl) : nullptr;
	m_callbackData = button.m_callbackData;
	m_switchInlineQuery = button.m_switchInlineQuery;
	m_switchInlineQueryCurrentChat = button.m_switchInlineQueryCurrentChat;
	//m_callbackGame = button.m_callbackGame ? new TelegramCallbackGame(*button.m_callbackGame) : nullptr; FIXIT
	m_pay = button.m_pay;
}

TelegramInlineKeyboardButton::~TelegramInlineKeyboardButton()
{
	delete m_loginUrl;
	// delete m_callbackGame; FIXIT
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
	if(!m_url.isEmpty()) json["url"] = m_url; else json["url"] = "https://google.com.ua";
	if(m_loginUrl) json["login_url"] = m_loginUrl->toJson();
	if(!m_callbackData.isEmpty()) json["callback_data"] = m_callbackData;
	if(!m_switchInlineQuery.isEmpty()) json["switch_inline_query"] = m_switchInlineQuery;
	if(!m_switchInlineQueryCurrentChat.isEmpty()) json["switch_inline_query_current_chat"] = m_switchInlineQueryCurrentChat;
	//json["callback_game"] = m_callbackGame.toJson(); FIXIT
	json["pay"] = m_pay;

	return json;
}

TelegramInlineKeyboardButton &TelegramInlineKeyboardButton::operator=(const TelegramInlineKeyboardButton &button)
{
	m_text = button.m_text;
	m_url = button.m_url;
	m_callbackData = button.m_callbackData;
	m_switchInlineQuery = button.m_switchInlineQuery;
	m_switchInlineQueryCurrentChat = button.m_switchInlineQueryCurrentChat;

	return *this;
}

TelegramCallbackGame *TelegramInlineKeyboardButton::callbackGame() const
{
	return m_callbackGame;
}

void TelegramInlineKeyboardButton::setCallbackGame(TelegramCallbackGame *callbackGame)
{
	m_callbackGame = callbackGame;
}
