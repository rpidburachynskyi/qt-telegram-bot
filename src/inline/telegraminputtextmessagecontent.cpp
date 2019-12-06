#include "telegraminputtextmessagecontent.h"

TelegramInputTextMessageContent::TelegramInputTextMessageContent(const QString &messageText,
																 const QString &parseMode,
																 const bool &disableWebPagePreview)
	: m_messageText(messageText),
	  m_parseMode(parseMode),
	  m_disableWebPagePreview(disableWebPagePreview)
{ }

TelegramInputMessageContent *TelegramInputTextMessageContent::clone() const
{
	return new TelegramInputTextMessageContent(*this);
}

QJsonObject TelegramInputTextMessageContent::toJson() const
{
	QJsonObject json;

	json["message_text"] = m_messageText;
	if(!m_parseMode.isEmpty()) json["parse_mode"] = m_parseMode;
	json["disable_web_page_preview"] = m_disableWebPagePreview;

	return json;
}
