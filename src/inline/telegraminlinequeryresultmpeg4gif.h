#ifndef TELEGRAMINLINEQUERYRESULTMPEG4GIF_H
#define TELEGRAMINLINEQUERYRESULTMPEG4GIF_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultMpeg4Gif : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultMpeg4Gif(const QString &id,
									  const QString &url,
									  const QString &thumbUrl,
									  const int &width,
									  const int &height,
									  const int &duration,
									  const QString &title,
									  const QString &maption,
									  const QString &parseMode,
									  const TelegramInlineKeyboardMarkup &replyMarkup,
									  const TelegramInputMessageContent *inputMessageContent);
	TelegramInlineQueryResultMpeg4Gif(const TelegramInlineQueryResultMpeg4Gif &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultMpeg4Gif(*this);
	}

	~TelegramInlineQueryResultMpeg4Gif() override;

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString url() const { return m_url; }
	/// Necessarily
	void setUrl(const QString &url) { m_url = url; }

	QString thumbUrl() const { return m_thumbUrl;}
	/// Necessarily
	void setThumbUrl(const QString &thumbUrl);

	int width() const { return m_width; }
	/// Optional
	void setWidth(int width) { m_width = width; }

	int height() const { return m_height; }
	/// Optional
	void setHeight(int height) { m_height = height;}

	int duration() const { return m_duration; }
	/// Optional
	void setDuration(int duration) { m_duration = duration; }

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
	QString m_thumbUrl;
	int m_width;
	int m_height;
	int m_duration;
	QString m_title;
	QString m_caption;
	QString m_parseMode;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTMPEG4GIF_H
