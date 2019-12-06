#include "telegraminlinequeryresultarticle.h"

TelegramInlineQueryResultArticle::
TelegramInlineQueryResultArticle(const QString &id,
								 const QString &title,
								 const TelegramInputMessageContent *inputMessageContent,
								 const TelegramInlineKeyboardMarkup replyMarkup,
								 const QString &url,
								 const QString &hideUrl,
								 const QString &description,
								 const int &thumbWidth,
								 const int &thumbHeight)
	: m_id(id),
	  m_title(title),
	  m_inputMessageContent(inputMessageContent->clone()),
	  m_replyMarkup(replyMarkup),
	  m_url(url),
	  m_hideUrl(hideUrl),
	  m_description(description),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight)
{

}

QJsonObject TelegramInlineQueryResultArticle::toJson() const
{
	QJsonObject json;

	json["type"] = "article";
	json["id"] = m_id;
	json["title"] = m_title;
	json["input_message_content"] = m_inputMessageContent->toJson();
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(!m_url.isEmpty()) json["url"] = m_url;
	if(!m_hideUrl.isEmpty()) json["hide_url"] = m_hideUrl;
	if(!m_description.isEmpty()) json["description"] = m_description;
	if(m_thumbWidth > -1) json["thumb_width"] = m_thumbWidth;
	if(m_thumbHeight > -1) json["thumb_height"] = m_thumbHeight;

	return json;
}

