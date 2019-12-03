#ifndef TELEGRAMINLINEKEYBOARDBUTTON_H
#define TELEGRAMINLINEKEYBOARDBUTTON_H

#include <QJsonObject>

class TelegramLoginUrl;
class TelegramCallbackGame;

class TelegramInlineKeyboardButton
{
public:
	TelegramInlineKeyboardButton(const QJsonObject &json);
	TelegramInlineKeyboardButton(const QString &text,
								 const QString &url = "",
								 const TelegramLoginUrl *loginUrl = nullptr,
								 const QString &callbackData = "",
								 const QString &switchInlineQuery = "",
								 const QString &switchInlineQueryCurrentChat = "",
								 const TelegramCallbackGame *callbackGame = nullptr,
								 const bool &pay = false);
	TelegramInlineKeyboardButton(const TelegramInlineKeyboardButton &button);
	~TelegramInlineKeyboardButton();

	QString text() const;
	void setText(const QString &text);

	QString url() const;
	void setUrl(const QString &url);

	TelegramLoginUrl *loginUrl() const;
	void setLoginUrl(TelegramLoginUrl *loginUrl);

	QString callbackData() const;
	void setCallbackData(const QString &callbackData);

	QString switchInlineQuery() const;
	void setSwitchInlineQuery(const QString &switchInlineQuery);

	QString switchInlineQueryCurrentChat() const;
	void setSwitchInlineQueryCurrentChat(const QString &switchInlineQueryCurrentChat);

	TelegramCallbackGame *callbackGame() const;
	void setCallbackGame(TelegramCallbackGame *callbackGame);

	bool pay() const;
	void setPay(bool pay);

	QJsonObject toJson() const;

	TelegramInlineKeyboardButton& operator=(const TelegramInlineKeyboardButton &button);

private:
	QString m_text;
	QString m_url;
	TelegramLoginUrl *m_loginUrl;
	QString m_callbackData;
	QString m_switchInlineQuery;
	QString m_switchInlineQueryCurrentChat;
	TelegramCallbackGame *m_callbackGame;
	bool m_pay;
};

#endif // TELEGRAMINLINEKEYBOARDBUTTON_H
