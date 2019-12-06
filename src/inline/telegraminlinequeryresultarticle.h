#ifndef TELEGRAMINLINEQUERYRESULTARTICLE_H
#define TELEGRAMINLINEQUERYRESULTARTICLE_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultArticle : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultArticle(const QString &id,
									 const QString &title,
									 const TelegramInputMessageContent *inputMessageContent,
									 const TelegramInlineKeyboardMarkup replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
									 const QString &url = "",
									 const QString &hideUrl = "",
									 const QString &description = "",
									 const int &thumbWidth = -1,
									 const int &thumbHeight = -1);

	TelegramInlineQueryResult * clone() const override {
		return new TelegramInlineQueryResultArticle(*this);
	}
	QJsonObject toJson() const override;

	inline QString id() const { return m_id; }
	/// Necessarily
	inline void setId(const QString &id) { m_id = id; }

	inline QString title() const { return m_title; }
	/// Necessarily
	inline void setTitle(const QString &title) { m_title = title; }

	inline const TelegramInputMessageContent *inputMessageContent() const {
		return m_inputMessageContent; }
	/// Necessarily
	inline void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		delete m_inputMessageContent;
		m_inputMessageContent = inputMessageContent->clone();
	}

	inline TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	/// Optional
	inline void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) {
		m_replyMarkup = replyMarkup; }

	inline QString url() const { return m_url; }
	/// Optional
	inline void setUrl(const QString &url) { m_url = url; }

	inline QString hideUrl() const { return m_url; }
	/// Optional
	inline void setHideUrl(const QString &hideUrl) { m_url = hideUrl; }

	inline QString description() const { return m_description; }
	/// Optional
	inline void setDescription(const QString &description) { m_description = description; }

	inline int thumbWidth() const { return m_thumbWidth; }
	/// Optional
	inline void setThumbWidth(int thumbWidth) { m_thumbWidth = thumbWidth; }

	inline int thumbHeight() const { return m_thumbHeight; }
	/// Optional
	inline void setThumbHeight(int thumbHeight) { m_thumbHeight = thumbHeight; }

private:
	QString m_id;
	QString m_title;
	TelegramInputMessageContent *m_inputMessageContent;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	QString m_url;
	QString m_hideUrl;
	QString m_description;
	int m_thumbWidth;
	int m_thumbHeight;
};

#endif // TELEGRAMINLINEQUERYRESULTARTICLE_H
