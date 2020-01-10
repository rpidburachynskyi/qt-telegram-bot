#ifndef TELEGRAMINLINEQUERYRESULTCACHED_H
#define TELEGRAMINLINEQUERYRESULTCACHED_H

#include "./telegraminlinequeryresult.h"
#include "./telegraminputmessagecontent.h"

class TelegramInlineQueryResultCached : public TelegramInlineQueryResult
{
protected:
	enum CachedFileType
	{
		Photo,
		Gif,
		Mpeg4Gif,
		Sticker,
		Video,
		Audio,
		Voice,
		Document,
	};

public:
	TelegramInlineQueryResultCached(const CachedFileType &cachedFileType,
									const QString &id,
									const QString &fileId,
									const QString &title = "",
									const QString &description = "",
									const QString &caption = "",
									const QString &parseMode = "",
									const TelegramInlineKeyboardMarkup replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
									const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultCached(const TelegramInlineQueryResultCached &result);
	TelegramInlineQueryResult *clone() const override {
		return new TelegramInlineQueryResultCached(*this);
	}
	~TelegramInlineQueryResultCached() override;

	QString id() const { return m_id; }
	void setId(const QString &id) { m_id = id; }

	QString fileId() const { return m_fileId; }
	void setFileId(const QString &fileId) { m_fileId = fileId; }

	QString title() const { return m_title; }
	void setTitle(const QString &title) { m_title = title; }

	QString description() const { return m_description; }
	void setDescription(const QString &description) { m_description = description; }

	QString caption() const { return m_caption; }
	void setCaption(const QString &caption) { m_caption = caption; }

	QString parseMode() const { return m_parseMode; }
	void setParseMode(const QString &parseMode) { m_parseMode = parseMode; }

	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) { m_replyMarkup = replyMarkup; }

	TelegramInputMessageContent *inputMessageContent() const { return m_inputMessageContent; }
	void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		delete m_inputMessageContent;
		m_inputMessageContent = inputMessageContent->clone();
	}

	QJsonObject toJson() const override;

private:
	CachedFileType m_cachedFileType;
	QString m_id;
	QString m_fileId;
	QString m_title;
	QString m_description;
	QString m_caption;
	QString m_parseMode;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;

	QString cachedFileTypeString() const;
};

#endif // TELEGRAMINLINEQUERYRESULTCACHED_H
