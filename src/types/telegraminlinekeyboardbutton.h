#ifndef TELEGRAMINLINEKEYBOARDBUTTON_H
#define TELEGRAMINLINEKEYBOARDBUTTON_H

#include <QJsonObject>

class TelegramLoginUrl;
class TelegramCallbackGame;

class TelegramInlineKeyboardButton
{
public:
	TelegramInlineKeyboardButton(const QString &text);
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
	bool m_pay;
};

#endif // TELEGRAMINLINEKEYBOARDBUTTON_H
