#ifndef TELEGRAMINLINEQUERYRESULTDOCUMENT_H
#define TELEGRAMINLINEQUERYRESULTDOCUMENT_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultDocument : public TelegramInlineQueryResult
{
public:
	enum DocumentMimeType
	{
		PDF,
		ZIP
	};

	TelegramInlineQueryResultDocument(const QString &id,
									  const QString &url,
									  const QString &title,
									  const DocumentMimeType &mimeType,
									  const QString &thumbUrl = "",
									  const int &thumbWidth = -1,
									  const int &thumbHeight = -1,
									  const QString &description = "",
									  const QString &caption = "",
									  const QString &parseMode = "",
									  const TelegramInlineKeyboardMarkup replyMarkup =
			   TelegramInlineKeyboardMarkup(QJsonObject()),
									  const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultDocument(const TelegramInlineQueryResultDocument &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultDocument(*this);
	}
	~TelegramInlineQueryResultDocument() override;

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString url() const { return m_url; }
	/// Necessarily
	void setUrl(const QString &url) { m_url = url; }

	QString mimeTypeString() const;
	DocumentMimeType mimeType() const { return m_mimeType; }
	/// Optional
	void setMimeType(const DocumentMimeType &mimeType) { m_mimeType = mimeType; }

	QString thumbUrl() const { return m_thumbUrl; }
	/// Necessarily
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

	int thumbWidth() const { return m_thumbWidth; }
	void setThumbWidth(int thumbWidth) { m_thumbWidth = thumbWidth;}

	int thumbHeight() const { return m_thumbHeight; }
	void setThumbHeight(int thumbHeight) { m_thumbHeight = thumbHeight; }

	QString title() const { return m_title; }
	/// Optional
	void setTitle(const QString &title) { m_title = title; }

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
	QString m_title;
	DocumentMimeType m_mimeType;
	QString m_thumbUrl;
	int m_thumbWidth;
	int m_thumbHeight;
	QString m_description;
	QString m_caption;
	QString m_parseMode;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;

};

#endif // TELEGRAMINLINEQUERYRESULTDOCUMENT_H
