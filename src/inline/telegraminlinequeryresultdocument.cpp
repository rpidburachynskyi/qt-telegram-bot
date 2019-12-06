#include "telegraminlinequeryresultdocument.h"


TelegramInlineQueryResultDocument::
TelegramInlineQueryResultDocument(const QString &id,
								  const QString &url,
								  const QString &title,
								  const TelegramInlineQueryResultDocument::DocumentMimeType &mimeType,
								  const QString &thumbUrl,
								  const int &thumbWidth,
								  const int &thumbHeight,
								  const QString &description,
								  const QString &caption,
								  const QString &parseMode,
								  const TelegramInlineKeyboardMarkup replyMarkup,
								  const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_url(url),
	  m_title(title),
	  m_mimeType(mimeType),
	  m_thumbUrl(thumbUrl),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight),
	  m_description(description),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultDocument::
TelegramInlineQueryResultDocument(const TelegramInlineQueryResultDocument &result)
	: m_id(result.m_id),
	  m_url(result.m_url),
	  m_title(result.m_title),
	  m_mimeType(result.m_mimeType),
	  m_thumbUrl(result.m_thumbUrl),
	  m_thumbWidth(result.m_thumbWidth),
	  m_thumbHeight(result.m_thumbHeight),
	  m_description(result.m_description),
	  m_caption(result.m_caption),
	  m_parseMode(result.m_parseMode),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultDocument::~TelegramInlineQueryResultDocument()
{
	delete m_inputMessageContent;
}

QString TelegramInlineQueryResultDocument::mimeTypeString() const
{
	switch (m_mimeType)
	{
		case PDF: return "application/pdf";
		case ZIP: return "application/zip";
	}
}

QJsonObject TelegramInlineQueryResultDocument::toJson() const
{
	QJsonObject json;

	json["type"] = "document";
	json["id"] = m_id;
	json["document_url"] = m_url;
	json["title"] = m_title;
	json["mime_type"] = mimeTypeString();
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_thumbUrl.isEmpty()) json["thumb_url"] = m_thumbUrl;
	if(m_thumbWidth > -1) json["thumb_width"] = m_thumbWidth;
	if(m_thumbHeight > -1) json["thumb_height"] = m_thumbHeight;
	if(!m_description.isEmpty()) json["description"] = m_description;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
