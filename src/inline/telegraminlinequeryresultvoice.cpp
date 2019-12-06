#include "telegraminlinequeryresultvoice.h"

TelegramInlineQueryResultVoice::
TelegramInlineQueryResultVoice(const QString &id,
							   const QString &url,
							   const QString &title,
							   const QString &caption,
							   const QString &parseMode,
							   const int &duration,
							   const TelegramInlineKeyboardMarkup &replyMarkup,
							   const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_url(url),
	  m_title(title),
	  m_caption(caption),
	  m_parseMode(parseMode),
	  m_duration(duration),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultVoice::
TelegramInlineQueryResultVoice(const TelegramInlineQueryResultVoice &result)
	: m_id(result.m_id),
	  m_url(result.m_url),
	  m_title(result.m_title),
	  m_caption(result.m_caption),
	  m_parseMode(result.m_parseMode),
	  m_duration(result.m_duration),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultVoice::~TelegramInlineQueryResultVoice()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultVoice::toJson() const
{
	QJsonObject json;

	json["type"] = "voice";
	json["id"] = m_id;
	json["voice_url"] = m_url;
	json["title"] = m_title;
	if(!m_caption.isEmpty()) json["caption"] = m_caption;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	if(m_duration > -1) json["voice_duration"] = m_duration;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
