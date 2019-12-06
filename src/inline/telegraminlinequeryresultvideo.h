#ifndef TELEGRAMINLINEQUERYRESULTVIDEO_H
#define TELEGRAMINLINEQUERYRESULTVIDEO_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultVideo : public TelegramInlineQueryResult
{
public:
	enum MimeType
	{
		TextHtml,
		VideoMp4
	};

	TelegramInlineQueryResultVideo(const QString &id,
								   const QString &url,
								   const QString &thumbUrl,
								   const QString &title,
								   const QString &caption = "",
								   const QString &parseMode = "",
								   const int &width = -1,
								   const int &height = -1,
								   const int &duration = -1,
								   const QString &description = "",
								   const TelegramInlineKeyboardMarkup &replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
								   const TelegramInputMessageContent *inputMessageContent = nullptr);

	TelegramInlineQueryResultVideo(const TelegramInlineQueryResultVideo &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultVideo(*this);
	}
	~TelegramInlineQueryResultVideo() override;

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString url() const { return m_url; }
	/// Necessarily
	void setUrl(const QString &url) { m_url = url; }

	QString thumbUrl() const { return m_thumbUrl; }
	/// Necessarily
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

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

	QString mimeType() const;
	/// Optional
	void setMimeType(const QString &mimeType);

	QString description() const { return m_description; }
	/// Optional
	void setDescription(const QString &description) { m_description = description; }

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
	QString m_mimeType;
	QString m_thumbUrl;
	QString m_title;
	QString m_caption;
	QString m_parseMode;
	int m_width;
	int m_height;
	int m_duration;
	QString m_description;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTVIDEO_H
