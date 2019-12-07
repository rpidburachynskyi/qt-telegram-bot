#include "telegrammessage.h"

#include <QVariant>
#include <QJsonArray>

TelegramMessage::TelegramMessage(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_id(json["message_id"].toVariant().toString()),
	  m_from(json["from"].toObject()),
	  m_date(json["date"].toInt()),
	  m_chat(json["chat"].toObject()),
	  m_forwardFrom(json["forward_from"].toObject()),
	  m_forwardFromChat(json["forward_from_chat"].toObject()),
	  m_forwardFromMessageId(json["forward_from_message_id"].toString()),
	  m_forwardSignature(json["forward_signature"].toString("")),
	  m_senderName(json["forward_signature"].toString("")),
	  m_forwardDate(json["forward_date"].toInt()),
	  m_editDate(json["edit_date"].toInt()),
	  m_mediaGroupId(json["media_group"].toString("")),
	  m_autorSignature(json["autor_signature"].toString("")),
	  m_text(json["text"].toString("")),
	  m_audio(json["audio"].toObject()),
	  m_document(json["document"].toObject()),
	  m_animation(json["animation"].toObject()),
	  m_sticker(json["sticker"].toObject()),
	  m_video(json["video"].toObject()),
	  m_voice(json["voice"].toObject()),
	  m_caption(json["caption"].toString("")),
	  m_contact(json["contact"].toObject()),
	  m_location(json["location"].toObject()),
	  m_venue(json["venue"].toObject()),
	  m_poll(json["poll"].toObject()),
	  m_leftChatMember(json["left_chat_member"].toObject()),
	  m_newChatTitle(json["new_chat_title"].toString("")),
	  m_deleteChatPhoto(json["delete_chat_photo"].toBool()),
	  m_groupChatCreated(json["delete_chat_photo"].toBool()),
	  m_supergroupChatCreated(json["delete_chat_photo"].toBool()),
	  m_channelChatCreate(json["delete_chat_photo"].toBool()),
	  m_migrateToChatId(json["migrate_to_chat_id"].toString("")),
	  m_migrateFromChatId(json["migrate_from_chat_id"].toString("")),
	  m_invoice(json["invoice"].toObject()),
	  m_successfulPayment(json["successful_payment"].toObject()),
	  m_connectedWebsite(json["connected_website"].toString("")),
	  m_passportData(json["passport_data"].toObject()),
	  m_replyMarkup(json["reply_markup"].toObject())
{
	QJsonArray photo = json["photo"].toArray();
	for(QJsonValueRef part : photo)
		m_photo.append(TelegramPhotoSize(part.toObject()));
	QJsonArray entities = json["entities"].toArray();
	for(QJsonValueRef entityObject : entities)
		m_entities.append(TelegramMessageEntity(entityObject.toObject()));
	QJsonArray captionEntities = json["caption_entities"].toArray();
	for(QJsonValueRef entityObject : captionEntities)
		m_captionEntities.append(TelegramMessageEntity(entityObject.toObject()));
	QJsonArray newChatPhoto = json["new_chat_photo"].toArray();
	for(QJsonValueRef part : newChatPhoto)
		m_newChatPhoto.append(TelegramPhotoSize(part.toObject()));
	QJsonArray members = json["new_chat_members"].toArray();
	for(QJsonValueRef member : members)
		m_newChatMembers.append(TelegramUser(member.toObject()));
}

TelegramMessage::~TelegramMessage()
{
	//delete m_replyToMessage;
	//delete m_pinnedMessage;
}
