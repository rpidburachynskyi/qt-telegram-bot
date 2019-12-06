#include "telegraminlinequeryresultvenue.h"

TelegramInlineQueryResultVenue::
TelegramInlineQueryResultVenue(const QString &id,
							   const double &latitude,
							   const double &longitude,
							   const QString &title,
							   const QString &address,
							   const QString &foursquareId,
							   const QString &foursquareType,
							   const QString &thumbUrl,
							   const int &thumbWidth,
							   const int &thumbHeight,
							   const TelegramInlineKeyboardMarkup &replyMarkup,
							   const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_latitude(latitude),
	  m_longitude(longitude),
	  m_title(title),
	  m_address(address),
	  m_foursquareId(foursquareId),
	  m_foursquareType(foursquareType),
	  m_thumbUrl(thumbUrl),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultVenue::
TelegramInlineQueryResultVenue(const TelegramInlineQueryResultVenue &result)
	: m_id(result.m_id),
	  m_latitude(result.m_latitude),
	  m_longitude(result.m_longitude),
	  m_title(result.m_title),
	  m_address(result.m_address),
	  m_foursquareId(result.m_foursquareId),
	  m_foursquareType(result.m_foursquareType),
	  m_thumbUrl(result.m_thumbUrl),
	  m_thumbWidth(result.m_thumbWidth),
	  m_thumbHeight(result.m_thumbHeight),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultVenue::~TelegramInlineQueryResultVenue()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultVenue::toJson() const
{
	QJsonObject json;

	json["type"] = "venue";
	json["id"] = m_id;
	json["latitude"] = m_latitude;
	json["longitude"] = m_longitude;
	json["title"] = m_title;
	json["address"] = m_address;
	if(!m_foursquareId.isEmpty()) json["foursquare_id"] = m_foursquareId;
	if(!m_foursquareType.isEmpty()) json["foursquare_type"] = m_foursquareType;
	if(!m_thumbUrl.isEmpty()) json["thumb_url"] = m_thumbUrl;
	if(m_thumbWidth > -1) json["thumb_width"] = m_thumbWidth;
	if(m_thumbHeight > -1) json["thumb_height"] = m_thumbHeight;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
