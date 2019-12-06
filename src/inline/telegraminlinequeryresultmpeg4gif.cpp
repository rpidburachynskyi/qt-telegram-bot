#include "telegraminlinequeryresultmpeg4gif.h"

TelegramInlineQueryResultMpeg4Gif::
TelegramInlineQueryResultMpeg4Gif(const QString &id,
								  const QString &url,
								  const QString &thumbUrl,
								  const int &width,
								  const int &height,
								  const int &duration,
								  const QString &title,
								  const QString &caption,
								  const QString &parseMode,
								  const TelegramInlineKeyboardMarkup &replyMarkup,
								  const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_url(url),
	  m_thumbUrl(thumbUrl),
	  m_width(width),
	  m_height(height),
	  m_duration(duration),
	  m_title(title),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ? nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultMpeg4Gif::
TelegramInlineQueryResultMpeg4Gif(const TelegramInlineQueryResultMpeg4Gif &result)
	: m_id(result.m_id),
	  m_url(result.m_url),
	  m_thumbUrl(result.m_thumbUrl),
	  m_width(result.m_width),
	  m_height(result.m_height),
	  m_duration(result.m_duration),
	  m_title(result.m_title),
	  m_caption(result.m_caption),
	  m_parseMode(result.m_parseMode),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultMpeg4Gif::~TelegramInlineQueryResultMpeg4Gif()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultMpeg4Gif::toJson() const
{
	QJsonObject json;

	json["type"] = "mpeg4_gif";
	json["id"] = m_id;
	json["mpeg4_url"] = m_url;
	json["thumb_url"] = m_thumbUrl;
	if(m_width > -1) json["mpeg4_width"] = m_width;
	if(m_height > -1) json["mpeg4_height"] = m_height;
	if(m_duration > -1) json["mpeg4_duration"] = m_duration;
	if(!m_title.isEmpty()) json["title"] = m_title;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
