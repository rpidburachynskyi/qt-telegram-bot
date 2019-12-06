#ifndef TELEGRAMINLINEQUERYRESULTVENUE_H
#define TELEGRAMINLINEQUERYRESULTVENUE_H

#include "telegraminlinequeryresult.h"
#include "telegraminputmessagecontent.h"

class TelegramInlineQueryResultVenue : public TelegramInlineQueryResult
{
public:
	TelegramInlineQueryResultVenue(const QString &id,
								   const double &latitude,
								   const double &longitude,
								   const QString &title,
								   const QString &address,
								   const QString &foursqureId = "",
								   const QString &foursquraType = "",
								   const QString &thumbUrl = "",
								   const int &thumbWidth = -1,
								   const int &thumbHeight = -1,
								   const TelegramInlineKeyboardMarkup &replyMarkup =
								   TelegramInlineKeyboardMarkup(QJsonObject()),
								   const TelegramInputMessageContent *inputMessageContent = nullptr);
	TelegramInlineQueryResultVenue(const TelegramInlineQueryResultVenue &result);

	TelegramInlineQueryResult * clone() const override {
		return new TelegramInlineQueryResultVenue(*this);
	}

	~TelegramInlineQueryResultVenue() override;

	QString id() const { return m_id; }
	void setId(const QString &id) { m_id = id; }

	double latitude() const { return m_latitude; }
	void setLatitude(double latitude) { m_latitude = latitude; }

	double longitude() const { return m_longitude; }
	void setLongitude(double longitude) { m_longitude = longitude; }

	QString title() const { return m_title; }
	void setTitle(const QString &title) { m_title = title; }

	QString address() const { return m_address; }
	void setAddress(const QString &address) { m_address = address; }

	QString foursquareId() const { return m_foursquareId; }
	void setFoursquareId(const QString &foursquareId) { m_foursquareId = foursquareId; }

	QString foursquareType() const { return m_foursquareType; }
	void setFoursquareType(const QString &foursquareType) { m_foursquareType = foursquareType; }

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
	QString m_address;
	QString m_foursquareId;
	QString m_foursquareType;
	QString m_thumbUrl;
	int m_thumbWidth;
	int m_thumbHeight;
	TelegramInlineKeyboardMarkup m_replyMarkup;
	TelegramInputMessageContent *m_inputMessageContent;
};

#endif // TELEGRAMINLINEQUERYRESULTVENUE_H
