#include "telegraminlinequeryresultvideo.h"

TelegramInlineQueryResultVideo::
TelegramInlineQueryResultVideo(const QString &id,
							   const QString &url,
							   const QString &thumbUrl,
							   const QString &title,
							   const QString &caption,
							   const QString &parseMode,
							   const int &width,
							   const int &height,
							   const int &duration,
							   const QString &description,
							   const TelegramInlineKeyboardMarkup &replyMarkup,
							   const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_url(url),
	  m_mimeType("video/mp4"),
	  m_thumbUrl(thumbUrl),
	  m_title(title),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_width(width),
	  m_height(height),
	  m_duration(duration),
	  m_description(description),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultVideo::
TelegramInlineQueryResultVideo(const TelegramInlineQueryResultVideo &result)
	: m_id(result.m_id),
	  m_url(result.m_url),
	  m_mimeType(result.m_mimeType),
	  m_thumbUrl(result.m_thumbUrl),
	  m_title(result.m_title),
	  m_parseMode(result.m_parseMode),
	  m_width(result.m_width),
	  m_height(result.m_height),
	  m_duration(result.m_duration),
	  m_description(result.m_description),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultVideo::~TelegramInlineQueryResultVideo()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultVideo::toJson() const
{
	QJsonObject json;

	json["type"] = "video";
	json["id"] = m_id;
	json["video_url"] = m_url;
	json["mime_type"] = m_mimeType;
	json["thumb_url"] = m_thumbUrl;
	if(!m_title.isEmpty()) json["title"] = m_title;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_width > -1) json["video_width"] = m_width;
	if(m_height > -1) json["video_height"] = m_height;
	if(m_duration > -1) json["video_duration"] = m_duration;
	if(!m_description.isEmpty()) json["description"] = m_description;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}

QString TelegramInlineQueryResultVideo::mimeType() const
{
	return m_mimeType;
}

void TelegramInlineQueryResultVideo::setMimeType(const QString &mimeType)
{
	m_mimeType = mimeType;
}
