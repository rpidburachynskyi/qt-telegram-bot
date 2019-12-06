#include "telegraminlinequeryresultcontact.h"

TelegramInlineQueryResultContact::
TelegramInlineQueryResultContact(const QString &id,
								 const QString &phoneNumber,
								 const QString &firstName,
								 const QString &lastName,
								 const QString &vcard,
								 const QString &thumbUrl,
								 const int &thumbWidth,
								 const int &thumbHeight,
								 const TelegramInlineKeyboardMarkup &replyMarkup,
								 const TelegramInputMessageContent *inputMessageContent)
	: m_id(id),
	  m_phoneNumber(phoneNumber),
	  m_firstName(firstName),
	  m_lastName(lastName),
	  m_vcard(vcard),
	  m_thumbUrl(thumbUrl),
	  m_thumbWidth(thumbWidth),
	  m_thumbHeight(thumbHeight),
	  m_replyMarkup(replyMarkup),
	  m_inputMessageContent(inputMessageContent == nullptr ?
								nullptr : inputMessageContent->clone())
{ }

TelegramInlineQueryResultContact::
TelegramInlineQueryResultContact(const TelegramInlineQueryResultContact &result)
	: m_id(result.m_id),
	  m_phoneNumber(result.m_phoneNumber),
	  m_firstName(result.m_firstName),
	  m_lastName(result.m_lastName),
	  m_vcard(result.m_vcard),
	  m_thumbUrl(result.m_thumbUrl),
	  m_thumbWidth(result.m_thumbWidth),
	  m_thumbHeight(result.m_thumbHeight),
	  m_replyMarkup(result.m_replyMarkup),
	  m_inputMessageContent(result.m_inputMessageContent == nullptr ?
								nullptr : result.m_inputMessageContent->clone())
{ }

TelegramInlineQueryResultContact::~TelegramInlineQueryResultContact()
{
	delete m_inputMessageContent;
}

QJsonObject TelegramInlineQueryResultContact::toJson() const
{
	QJsonObject json;

	json["type"] = "contact";
	json["id"] = m_id;
	json["phone_number"] = m_phoneNumber;
	json["first_name"] = m_firstName;
	if(!m_lastName.isEmpty()) json["last_name"] = m_lastName;
	if(!m_vcard.isEmpty()) json["vcard"] = m_vcard;
	if(!m_thumbUrl.isEmpty()) json["thumb_url"] = m_thumbUrl;
	if(m_thumbWidth > -1) json["thumb_width"] = m_thumbWidth;
	if(m_thumbHeight > -1) json["thumb_height"] = m_thumbHeight;
	if(m_replyMarkup.isNotNull()) json["reply_markup"] = m_replyMarkup.toJson();
	if(m_inputMessageContent) json["input_message_content"] = m_inputMessageContent->toJson();

	return json;
}
