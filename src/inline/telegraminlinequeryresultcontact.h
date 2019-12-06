#ifndef TELEGRAMINLINEQUERYRESULTCONTACT_H
#define TELEGRAMINLINEQUERYRESULTCONTACT_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultContact : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultContact(const QString &id,
									 const QString &phoneNumber,
									 const QString &firstName,
									 const QString &lastName = "",
									 const QString &vcard = "",
									 const QString &thumbUrl = "",
									 const int &thumbWidth = -1,
									 const int &thumbHeight = -1,
									 const TelegramInlineKeyboardMarkup &replyMarkup =
									 TelegramInlineKeyboardMarkup(QJsonObject()),
									 const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultContact (const TelegramInlineQueryResultContact &result);
	TelegramInlineQueryResult * clone() const override {
		return new TelegramInlineQueryResultContact(*this);
	}
	~TelegramInlineQueryResultContact() override;

	QString id() const { return m_id; }
	void setId(const QString &id) { m_id = id; }

	QString phoneNumber() const { return m_phoneNumber; }
	void setPhoneNumber(const QString &phoneNumber) { m_phoneNumber = phoneNumber; }

	QString firstName() const { return m_firstName; }
	void setFirstName(const QString &firstName) { m_firstName = firstName; }

	QString lastName() const { return m_lastName; }
	void setLastName(const QString &lastName) { m_lastName = lastName;}

	QString vcard() const { return m_vcard; }
	void setVcard(const QString &vcard) { m_vcard = vcard;}

	QString thumbUrl() const { return m_thumbUrl; }
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

	int thumbWidth() const { return m_thumbWidth; }
	void setThumbWidth(int thumbWidth) { m_thumbWidth = thumbWidth;}

	int thumbHeight() const { return m_thumbHeight; }
	void setThumbHeight(int thumbHeight) { m_thumbHeight = thumbHeight;}

	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) { m_replyMarkup = replyMarkup; }

	TelegramInputMessageContent *inputMessageContent() const { return m_inputMessageContent; }
	void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		m_inputMessageContent = inputMessageContent->clone();
	}

	QJsonObject toJson() const override;

private:
	QString m_id;
	QString m_phoneNumber;
	QString m_firstName;
	QString m_lastName;
	QString m_vcard;
	QString m_thumbUrl;
	int m_thumbWidth;
	int m_thumbHeight;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTCONTACT_H
