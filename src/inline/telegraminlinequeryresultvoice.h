#ifndef TELEGRAMINLINEQUERYRESULTVOICE_H
#define TELEGRAMINLINEQUERYRESULTVOICE_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultVoice : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultVoice(const QString &id,
								   const QString &url,
								   const QString &title,
								   const QString &caption = "",
								   const QString &parseMode = "",
								   const int &duration = -1,
								   const TelegramInlineKeyboardMarkup &replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
								   const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultVoice(const TelegramInlineQueryResultVoice &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultVoice(*this);
	}
	~TelegramInlineQueryResultVoice() override;

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString url() const { return m_url; }
	/// Necessarily
	void setUrl(const QString &url) { m_url = url; }

	QString title() const { return m_title; }
	/// Optional
	void setTitle(const QString &title) { m_title = title; }

	QString mimeType() const;
	/// Optional
	void setMimeType(const QString &mimeType);

	QString caption() const { return m_caption; }
	/// Optional
	void setCaption(const QString &caption) { m_caption = caption; }

	QString parseMode() const { return m_parseMode; }
	/// Optional
	void setParseMode(const QString &parseMode) { m_parseMode = parseMode; }

	int duration() const { return m_duration; }
	/// Optional
	void setDuration(int duration) { m_duration = duration; }

	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	/// Optional
	void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) {
		m_replyMarkup = replyMarkup;
	}
	const TelegramInputMessageContent *inputMessageContent() const { return m_inputMessageContent; }
	/// Optional
	void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		delete m_inputMessageContent;
		m_inputMessageContent = inputMessageContent->clone();
	}

	QJsonObject toJson() const override;

private:
	QString m_id;
	QString m_url;
	QString m_title;
	QString m_caption;
	QString m_parseMode;
	int m_duration;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTVOICE_H
