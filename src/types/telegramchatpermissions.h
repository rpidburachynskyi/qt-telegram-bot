#ifndef TELEGRAMCHATPERMISSIONS_H
#define TELEGRAMCHATPERMISSIONS_H

#include <QJsonObject>

class TelegramChatPermissions
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

	bool canSendMessages() const;
	bool canSendMediaMessages() const;
	bool canSendPolls() const;
	bool canSendOtherMessages() const;
	bool canAddWebPagePreviews() const;
	bool canChangeInfo() const;
	bool canInviteUsers() const;
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
