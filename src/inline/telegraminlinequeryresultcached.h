#ifndef TELEGRAMINLINEQUERYRESULTCACHED_H
#define TELEGRAMINLINEQUERYRESULTCACHED_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

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
};

#endif // TELEGRAMINLINEQUERYRESULTCACHED_H
