#ifndef TELEGRAMLOGINURL_H
#define TELEGRAMLOGINURL_H

#include "telegrambasetypes.h"

class TelegramLoginUrl : public TelegramBaseTypes
{
public:
	TelegramLoginUrl(const QJsonObject &json);

	// Necessarily
	QString url() const;
	// Optional
	QString forwardText() const;
	// Optional
	QString botUsername() const;
	// Optional
	bool requestWriteAccess() const;

	QJsonObject toJson() const;

private:
	QString m_url;
	QString m_forwardText;
	QString m_botUsername;
	bool m_requestWriteAccess;
};

#endif // TELEGRAMLOGINURL_H
