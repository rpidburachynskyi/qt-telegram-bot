#include "telegraminlinequeryresultlocation.h"

TelegramInlineQueryResultLocation::
TelegramInlineQueryResultLocation(const QString &id,
								  const double &latitude,
								  const double &longitude,
								  const QString &title,
								  const int &livePeriod,
								  const QString &thumbUrl,
								  const int &thumbWidth,
								  const int &thumbHeight,
								  const TelegramInlineKeyboardMarkup &replyMarkup,
								  const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_latitude(latitude),
	  m_longitude(longitude),
	  m_title(title),
	  m_livePeriod(livePeriod),
	  m_thumbUrl(thumbUrl),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultLocation::
TelegramInlineQueryResultLocation(const TelegramInlineQueryResultLocation &result)
	: m_id(result.m_id),
	  m_latitude(result.m_latitude),
	  m_longitude(result.m_longitude),
	  m_title(result.m_title),
	  m_livePeriod(result.m_livePeriod),
	  m_thumbUrl(result.m_thumbUrl),
	  m_thumbWidth(result.m_thumbWidth),
	  m_thumbHeight(result.m_thumbHeight),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultLocation::~TelegramInlineQueryResultLocation()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultLocation::toJson() const
{
	QJsonObject json;

	json["type"] = "location";
	json["id"] = m_id;
	json["latitude"] = m_latitude;
	json["longitude"] = m_longitude;
	json["title"] = m_title;
	if(m_livePeriod >= 60 && m_livePeriod <= 86400) json["live_period"] = m_thumbHeight;
	if(!m_thumbUrl.isEmpty()) json["thumb_url"] = m_thumbUrl;
	if(m_thumbWidth > -1) json["thumb_width"] = m_thumbWidth;
	if(m_thumbHeight > -1) json["thumb_height"] = m_thumbHeight;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
