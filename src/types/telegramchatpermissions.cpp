#include "telegramchatpermissions.h"

TelegramChatPermissions::TelegramChatPermissions(const QJsonObject &json)
	: TelegramBaseTypes(json),
	  m_canSendMessages(json["can_send_messages"].toBool()),
	  m_canSendMediaMessages(json["can_send_media_messages"].toBool()),
	  m_canSendPolls(json["can_send_polls"].toBool()),
	  m_canSendOtherMessages(json["can_send_other_messages"].toBool()),
	  m_canAddWebPagePreviews(json["can_add_web_page_previews"].toBool()),
	  m_canChangeInfo(json["can_change_info"].toBool()),
	  m_canInviteUsers(json["can_invite_users"].toBool()),
	  m_canPinMessages(json["can_pin_messages"].toBool())
{ }

TelegramChatPermissions::TelegramChatPermissions(const bool &canSendMessages,
												 const bool &canSendMediaMessages,
												 const bool &canSendPolls,
												 const bool &canSendOtherMessages,
												 const bool &canAddWebPagePreviews,
												 const bool &canChangeInfo,
												 const bool &canInviteUsers,
												 const bool &canPinMessages)
	: TelegramBaseTypes(false),
	  m_canSendMessages(canSendMessages),
	  m_canSendMediaMessages(canSendMediaMessages),
	  m_canSendPolls(canSendPolls),
	  m_canSendOtherMessages(canSendOtherMessages),
	  m_canAddWebPagePreviews(canAddWebPagePreviews),
	  m_canChangeInfo(canChangeInfo),
	  m_canInviteUsers(canInviteUsers),
	  m_canPinMessages(canPinMessages)
{ }

bool TelegramChatPermissions::canSendMessages() const
{
	return m_canSendMessages;
}

bool TelegramChatPermissions::canSendMediaMessages() const
{
	return m_canSendMediaMessages;
}

bool TelegramChatPermissions::canSendPolls() const
{
	return m_canSendPolls;
}

bool TelegramChatPermissions::canSendOtherMessages() const
{
	return m_canSendOtherMessages;
}

bool TelegramChatPermissions::canAddWebPagePreviews() const
{
	return m_canAddWebPagePreviews;
}

bool TelegramChatPermissions::canChangeInfo() const
{
	return m_canChangeInfo;
}

bool TelegramChatPermissions::canInviteUsers() const
{
	return m_canInviteUsers;
}

bool TelegramChatPermissions::canPinMessages() const
{
	return m_canPinMessages;
}

void TelegramChatPermissions::setCanSendMessages(bool canSendMessages)
{
	m_canSendMessages = canSendMessages;
}

void TelegramChatPermissions::setCanSendMediaMessages(bool canSendMediaMessages)
{
	m_canSendMediaMessages = canSendMediaMessages;
}

void TelegramChatPermissions::setCanSendPolls(bool canSendPolls)
{
	m_canSendPolls = canSendPolls;
}

void TelegramChatPermissions::setCanSendOtherMessages(bool canSendOtherMessages)
{
	m_canSendOtherMessages = canSendOtherMessages;
}

void TelegramChatPermissions::setCanAddWebPagePreviews(bool canAddWebPagePreviews)
{
	m_canAddWebPagePreviews = canAddWebPagePreviews;
}

void TelegramChatPermissions::setCanChangeInfo(bool canChangeInfo)
{
	m_canChangeInfo = canChangeInfo;
}

void TelegramChatPermissions::setCanInviteUsers(bool canInviteUsers)
{
	m_canInviteUsers = canInviteUsers;
}

void TelegramChatPermissions::setCanPinMessages(bool canPinMessages)
{
	m_canPinMessages = canPinMessages;
}

QJsonObject TelegramChatPermissions::toJson() const
{
	QJsonObject json;

	json["can_send_messages"] = m_canSendMessages;
	json["can_send_media_messages"] = m_canSendMediaMessages;
	json["can_send_polls"] = m_canSendPolls;
	json["can_send_other_messages"] = m_canSendOtherMessages;
	json["can_add_web_page_previews"] = m_canAddWebPagePreviews;
	json["can_change_info"] = m_canChangeInfo;
	json["can_invite_users"] = m_canInviteUsers;
	json["can_pin_messages"] = m_canPinMessages;

	return json;
}
