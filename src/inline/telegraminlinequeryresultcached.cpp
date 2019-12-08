#include "telegraminlinequeryresultcached.h"

TelegramInlineQueryResultCached::
TelegramInlineQueryResultCached(const TelegramInlineQueryResultCached::CachedFileType &cachedFileType,
								const QString &id,
								const QString &fileId,
								const QString &title,
								const QString &description,
								const QString &caption,
								const QString &parseMode,
								const TelegramInlineKeyboardMarkup replyMarkup,
								const TelegramInputMessageContent *inputMessageContent)
	: m_cachedFileType(cachedFileType),
	  m_id(id),
	  m_fileId(fileId),
	  m_title(title),
	  m_description(description),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultCached::
TelegramInlineQueryResultCached(const TelegramInlineQueryResultCached &result)
	: m_cachedFileType(result.m_cachedFileType),
	  m_id(result.m_id),
	  m_fileId(result.m_fileId),
	  m_title(result.m_title),
	  m_description(result.m_description),
	  m_caption(result.m_caption),
	  m_parseMode(result.m_parseMode),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{

}

TelegramInlineQueryResultCached::~TelegramInlineQueryResultCached()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultCached::toJson() const
{
	QJsonObject json;

	json["id"] = m_id;
	switch (m_cachedFileType)
	{
		case Photo:
		{
			json["type"] = "photo";
			json["photo_file_id"] = m_fileId;
		}
	}
	if(!m_title.isEmpty()) json["title"] = m_title;
	if(!m_description.isEmpty()) json["description"] = m_description;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
