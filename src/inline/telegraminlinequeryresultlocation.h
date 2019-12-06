#ifndef TELEGRAMINLINEQUERYRESULTLOCATION_H
#define TELEGRAMINLINEQUERYRESULTLOCATION_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultLocation : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultLocation(const QString &id,
			const double &latitude,
			const double &longitude,
			const QString &title,
			const int &livePeriod = -1,
			const QString &thumbUrl = "",
			const int &thumbWidth = -1,
			const int &thumbHeight = -1,
			const TelegramInlineKeyboardMarkup &replyMarkup =
			TelegramInlineKeyboardMarkup(QJsonObject()),
			const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultLocation(const TelegramInlineQueryResultLocation &result);
	TelegramInlineQueryResult * clone() const override {
		return new TelegramInlineQueryResultLocation(*this);
	}

	~TelegramInlineQueryResultLocation() override;

	QString id() const { return m_id; }
	void setId(const QString &id) { m_id = id; }

	double latitude() const { return m_latitude; }
	void setLatitude(double latitude) { m_latitude = latitude; }

	double longitude() const { return m_longitude; }
	void setLongitude(double longitude) { m_longitude = longitude; }

	QString title() const { return m_title; }
	void setTitle(const QString &title) { m_title = title;}

	int livePeriod() const { return m_livePeriod; }
	void setLivePeriod(int livePeriod) { m_livePeriod = livePeriod; }

	QString thumbUrl() const { return m_thumbUrl; }
	void setThumbUrl(const QString &thumbUrl) { m_thumbUrl = thumbUrl; }

	int thumbWidth() const { return m_thumbWidth; }
	void setThumbWidth(int thumbWidth) { m_thumbWidth = thumbWidth;}

	int thumbHeight() const { return m_thumbHeight; }
	void setThumbHeight(int thumbHeight) { m_thumbHeight = thumbHeight;}

	TelegramInlineKeyboardMarkup replyMarkup() const { return m_replyMarkup; }
	void setReplyMarkup(const TelegramInlineKeyboardMarkup &replyMarkup) { m_replyMarkup = replyMarkup; }

	TelegramInputMessageContent *inputMessageContent() const { return m_inputMessageContent; }
	void setInputMessageContent(TelegramInputMessageContent *inputMessageContent) {
		m_inputMessageContent = inputMessageContent->clone();
	}

	QJsonObject toJson() const override;

private:
	QString m_id;
	double m_latitude;
	double m_longitude;
	QString m_title;
	int m_livePeriod;
	QString m_thumbUrl;
	int m_thumbWidth;
	int m_thumbHeight;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTLOCATION_H
