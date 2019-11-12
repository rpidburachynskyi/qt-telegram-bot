#ifndef TELEGRAMCHATMEMBER_H
#define TELEGRAMCHATMEMBER_H

#include "telegramuser.h"

#include <QJsonObject>

class TelegramChatMember
{
public:
	TelegramChatMember(const QJsonObject &json);

	TelegramUser user() const;
	QString status() const;
	int untilDate() const;
	bool canBeEdited() const;
	bool canPostMessages() const;
	bool canEditMessages() const;
	bool canDeleteMessages() const;
	bool canRestrictMembers() const;
	bool canPromoteMembers() const;
	bool canChangeInfo() const;
	bool canInviteUsers() const;
	bool canPinMessages() const;
	bool isMember() const;
	bool canSendMessages() const;
	bool canSendMediaMessages() const;
	bool canSendPolls() const;
	bool canSendOtherMessages() const;
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
