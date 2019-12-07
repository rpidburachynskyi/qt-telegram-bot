#include "telegramchatmember.h"

TelegramChatMember::TelegramChatMember(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_user(json["user"].toObject()),
	  m_status(json["status"].toString()),
	  m_untilDate(json["untilDate"].toInt()),
	  m_canBeEdited(json["can_be_edited"].toBool()),
	  m_canPostMessages(json["can_post_messages"].toBool()),
	  m_canEditMessages(json["can_edit_messages"].toBool()),
	  m_canDeleteMessages(json["can_delete_messages"].toBool()),
	  m_canRestrictMembers(json["can_restrict_members"].toBool()),
	  m_canPromoteMembers(json["can_promote_members"].toBool()),
	  m_canChangeInfo(json["can_change_info"].toBool()),
	  m_canInviteUsers(json["can_invite_users"].toBool()),
	  m_canPinMessages(json["can_pin_messages"].toBool()),
	  m_isMember(json["is_member"].toBool()),
	  m_canSendMessages(json["can_send_messages"].toBool()),
	  m_canSendMediaMessages(json["can_send_media_messages"].toBool()),
	  m_canSendPolls(json["can_send_polls"].toBool()),
	  m_canSendOtherMessages(json["can_send_other_messages"].toBool()),
	  m_canAddWebPagePreviews(json["can_add_web_page_previews"].toBool())
{ }

TelegramUser TelegramChatMember::user() const
{
	return m_user;
}

QString TelegramChatMember::status() const
{
	return m_status;
}

int TelegramChatMember::untilDate() const
{
	return m_untilDate;
}

bool TelegramChatMember::canBeEdited() const
{
	return m_canBeEdited;
}

bool TelegramChatMember::canPostMessages() const
{
	return m_canPostMessages;
}

bool TelegramChatMember::canEditMessages() const
{
	return m_canEditMessages;
}

bool TelegramChatMember::canDeleteMessages() const
{
	return m_canDeleteMessages;
}

bool TelegramChatMember::canRestrictMembers() const
{
	return m_canRestrictMembers;
}

bool TelegramChatMember::canPromoteMembers() const
{
	return m_canPromoteMembers;
}

bool TelegramChatMember::canChangeInfo() const
{
	return m_canChangeInfo;
}

bool TelegramChatMember::canInviteUsers() const
{
	return m_canInviteUsers;
}

bool TelegramChatMember::canPinMessages() const
{
	return m_canPinMessages;
}

bool TelegramChatMember::isMember() const
{
	return m_isMember;
}

bool TelegramChatMember::canSendMessages() const
{
	return m_canSendMessages;
}

bool TelegramChatMember::canSendMediaMessages() const
{
	return m_canSendMediaMessages;
}

bool TelegramChatMember::canSendPolls() const
{
	return m_canSendPolls;
}

bool TelegramChatMember::canSendOtherMessages() const
{
	return m_canSendOtherMessages;
}

bool TelegramChatMember::canAddWebPagePreviews() const
{
	return m_canAddWebPagePreviews;
}
