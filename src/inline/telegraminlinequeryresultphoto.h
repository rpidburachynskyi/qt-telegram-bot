#ifndef TELEGRAMINLINEQUERYRESULTPHOTO_H
#define TELEGRAMINLINEQUERYRESULTPHOTO_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultPhoto : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultPhoto(const QString &id,
								   const QString &photoUrl,
								   const QString &thumbUrl,
								   const int &photoWidth = -1,
								   const int &photoHeight = -1,
								   const QString &title = "",
								   const QString &description = "",
								   const QString &caption = "",
								   const QString &parseMode = "",
								   const TelegramInlineKeyboardMarkup replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
								   const TelegramInputMessageContent *inputMessageContent = nullptr);

	QString id() const { return m_id; }
	/// Necessarily
	void setId(const QString &id) { m_id = id; }

	QString photoUrl() const { return m_photoUrl; }
	/// Necessarily
	void setPhotoUrl(const QString &photoUrl) { m_photoUrl = photoUrl; }

	QString thumbUrl() const { return m_thumbUrl; }
	/// Necessarily
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

	int photoWidth() const { return m_photoWidth; }
	/// Optional
	void setPhotoWidth(int photoWidth) { m_photoWidth = photoWidth; }

	int photoHeight() const { return m_photoHeight; }
	/// Optional
	void setPhotoHeight(int photoHeight) { m_photoHeight = photoHeight; }

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

	TelegramInlineQueryResult * clone() const override {
		return new TelegramInlineQueryResultPhoto(*this);
	}
	QJsonObject toJson() const override;

private:
	QString m_id;
	QString m_photoUrl;
	QString m_thumbUrl;
	int m_photoWidth;
	int m_photoHeight;
	QString m_title;
	QString m_description;
	QString m_caption;
	QString m_parseMode;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTPHOTO_H
