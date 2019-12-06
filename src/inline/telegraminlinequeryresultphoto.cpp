#include "telegraminlinequeryresultphoto.h"

TelegramInlineQueryResultPhoto::
TelegramInlineQueryResultPhoto(const QString &id,
							   const QString &photoUrl,
							   const QString &thumbUrl,
							   const int &photoWidth,
							   const int &photoHeight,
							   const QString &title,
							   const QString &description,
							   const QString &caption,
							   const QString &parseMode,
							   const TelegramInlineKeyboardMarkup replyMarkup,
							   const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_photoUrl(photoUrl),
	  m_thumbUrl(thumbUrl),
	  m_photoWidth(photoWidth),
	  m_photoHeight(photoHeight),
	  m_title(title),
	  m_description(description),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ? nullptr : inputMessageContent->clone())
{ }

QJsonObject TelegramInlineQueryResultPhoto::toJson() const
{
	QJsonObject json;

	json["id"] = m_id;
	json["type"] = "photo";
	json["photo_url"] = m_photoUrl;
	json["thumb_url"] = m_thumbUrl;
	if(m_photoWidth > -1) json["photo_width"] = m_photoWidth;
	if(m_photoHeight > -1) json["photo_height"] = m_photoHeight;
	if(!m_title.isEmpty()) json["title"] = m_title;
	if(!m_description.isEmpty()) json["description"] = m_description;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
