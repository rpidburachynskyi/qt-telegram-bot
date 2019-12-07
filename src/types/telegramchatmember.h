#ifndef TELEGRAMCHATMEMBER_H
#define TELEGRAMCHATMEMBER_H

#include "telegramuser.h"

class TelegramChatMember : public TelegramBaseTypes
{
public:
	TelegramChatMember(const QJsonObject &json);

	/// Necessarily
	TelegramUser user() const;
	/// Necessarily
	QString status() const;
	/// Necessarily
	int untilDate() const;
	/// Optional
	bool canBeEdited() const;
	/// Optional
	bool canPostMessages() const;
	/// Optional
	bool canEditMessages() const;
	/// Optional
	bool canDeleteMessages() const;
	/// Optional
	bool canRestrictMembers() const;
	/// Optional
	bool canPromoteMembers() const;
	/// Optional
	bool canChangeInfo() const;
	/// Optional
	bool canInviteUsers() const;
	/// Optional
	bool canPinMessages() const;
	/// Optional
	bool isMember() const;
	/// Optional
	bool canSendMessages() const;
	/// Optional
	bool canSendMediaMessages() const;
	/// Optional
	bool canSendPolls() const;
	/// Optional
	bool canSendOtherMessages() const;
	/// Optional
	bool canAddWebPagePreviews() const;

private:
	TelegramUser m_user;
	QString m_status;
	int m_untilDate;
	bool m_canBeEdited;
	bool m_canPostMessages;
	bool m_canEditMessages;
	bool m_canDeleteMessages;
	bool m_canRestrictMembers;
	bool m_canPromoteMembers;
	bool m_canChangeInfo;
	bool m_canInviteUsers;
	bool m_canPinMessages;
	bool m_isMember;
	bool m_canSendMessages;
	bool m_canSendMediaMessages;
	bool m_canSendPolls;
	bool m_canSendOtherMessages;
	bool m_canAddWebPagePreviews;
};

#endif // TELEGRAMCHATMEMBER_H
