#ifndef TELEGRAMCHATPERMISSIONS_H
#define TELEGRAMCHATPERMISSIONS_H

#include "telegrambasetypes.h"

class TelegramChatPermissions : public TelegramBaseTypes
{
public:
	TelegramChatPermissions(const QJsonObject &json);
	TelegramChatPermissions(const bool &canSendMessages,
							const bool &canSendMediaMessages,
							const bool &canSendPolls,
							const bool &canSendOtherMessages,
							const bool &canAddWebPagePreviews,
							const bool &canChangeInfo,
							const bool &canInviteUsers,
							const bool &canPinMessages);

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
	/// Optional
	bool canChangeInfo() const;
	/// Optional
	bool canInviteUsers() const;
	/// Optional
	bool canPinMessages() const;

	void setCanSendMessages(bool canSendMessages);
	void setCanSendMediaMessages(bool canSendMediaMessages);
	void setCanSendPolls(bool canSendPolls);
	void setCanSendOtherMessages(bool canSendOtherMessages);
	void setCanAddWebPagePreviews(bool canAddWebPagePreviews);
	void setCanChangeInfo(bool canChangeInfo);
	void setCanInviteUsers(bool canInviteUsers);
	void setCanPinMessages(bool canPinMessages);

	QJsonObject toJson() const;

private:
	bool m_canSendMessages;
	bool m_canSendMediaMessages;
	bool m_canSendPolls;
	bool m_canSendOtherMessages;
	bool m_canAddWebPagePreviews;
	bool m_canChangeInfo;
	bool m_canInviteUsers;
	bool m_canPinMessages;
};

#endif // TELEGRAMCHATPERMISSIONS_H
