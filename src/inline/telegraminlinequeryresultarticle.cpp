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
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone()),
	  m_replyMarkup(replyMarkup),
	  m_url(url),
	  m_hideUrl(hideUrl),
	  m_description(description),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight)
{

}

TelegramInlineQueryResultArticle::
TelegramInlineQueryResultArticle(const TelegramInlineQueryResultArticle &result)
	: m_id(result.m_id),
	  m_title(result.m_title),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone()),
	  m_replyMarkup(result.m_replyMarkup),
	  m_url(result.m_url),
	  m_hideUrl(result.m_hideUrl),
	  m_description(result.m_description),
	  m_thumbWidth(result.m_thumbWidth),
	  m_thumbHeight(result.m_thumbHeight)
{ }

TelegramInlineQueryResultArticle::~TelegramInlineQueryResultArticle()
{
	delete m_inputMessageContent;
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

