#ifndef TELEGRAMINLINEQUERYRESULTGIF_H
#define TELEGRAMINLINEQUERYRESULTGIF_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultGif : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultGif(const QString &id,
								 const QString &gifUrl,
								 const QString &thumbUrl,
								 const int &gifWidth = -1,
								 const int &gifHeight = -1,
								 const int &gifDuration = -1,
								 const QString &title = "",
								 const QString &caption = "",
								 const QString &parseMode = "",
								 const TelegramInlineKeyboardMarkup replyMarkup =
		  TelegramInlineKeyboardMarkup(QJsonObject()),
								 const TelegramInputMessageContent *inputMessageContent = nullptr);

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString gifUrl() const { return m_gifUrl; }
	/// Necessarily
	void setGifUrl(const QString &gifUrl) { m_gifUrl = gifUrl; }

	QString thumbUrl() const { return m_thumbUrl; }
	/// Necessarily
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

	int gifWidth() const { return m_gifWidth; }
	/// Optional
	void setGifWidth(int gifWidth) { m_gifWidth = gifWidth; }

	int gifHeight() const { return m_gifHeight; }
	/// Optional
	void setGifHeight(int gifHeight) { m_gifHeight = gifHeight; }

	int gitDuration() const { return m_gifDuration; }
	/// Optional
	void setGifDuration(int gifDuration) { m_gifDuration = gifDuration; }

	QString title() const { return m_title; }
	/// Optional
	void setTitle(const QString &title) { m_title = title; }

	QString caption() const { return m_caption; }
	/// Optional
	void setCaption(const QString &caption) { m_caption = caption; }

	QString parseMode() const { return m_parseMode; }
	/// Optional
	void setParseMode(const QString &parseMode) { m_parseMode = parseMode; }

	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	/// Optional
	void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) {
		m_replyMarkup = replyMarkup;
	}

	TelegramInputMessageContent *inputMessageContent() const {
		return m_inputMessageContent;
	}
	void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		delete m_inputMessageContent;
		m_inputMessageContent = inputMessageContent->clone();
	}

	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultGif(*this);
	}
	QJsonObject toJson() const override;

private:
	QString m_id;
	QString m_gifUrl;
	QString m_thumbUrl;
	int m_gifWidth;
	int m_gifHeight;
	int m_gifDuration;
	QString m_title;
	QString m_caption;
	QString m_parseMode;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;

};

#endif // TELEGRAMINLINEQUERYRESULTGIF_H
