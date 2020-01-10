#ifndef TELEGRAMINLINEQUERYRESULTAUDIO_H
#define TELEGRAMINLINEQUERYRESULTAUDIO_H

#include "./telegraminlinequeryresult.h"
#include "./telegraminputmessagecontent.h"

class TelegramInlineQueryResultAudio : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultAudio(const QString &id,
								   const QString &url,
								   const QString &title,
								   const QString &caption = "",
								   const QString &parseMode = "",
								   const QString &performer = "",
								   const int &duration = -1,
								   const TelegramInlineKeyboardMarkup &replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
								   const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultAudio(const TelegramInlineQueryResultAudio &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultAudio(*this);
	}
	~TelegramInlineQueryResultAudio() override;

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString url() const { return m_url; }
	/// Necessarily
	void setUrl(const QString &url) { m_url = url; }

	QString title() const { return m_title; }
	/// Optional
	void setTitle(const QString &title) { m_title = title; }

	QString caption() const { return m_caption; }
	/// Optional
	void setCaption(const QString &caption) { m_caption = caption; }

	QString parseMode() const { return m_parseMode; }
	/// Optional
	void setParseMode(const QString &parseMode) { m_parseMode = parseMode; }

	QString performer() const { return m_performer; }
	/// Optional
	void setPerformer(const QString &performer) { m_performer = performer; }

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
	QString m_performer;
	int m_duration;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;

};

#endif // TELEGRAMINLINEQUERYRESULTAUDIO_H
