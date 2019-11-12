#ifndef TELEGRAMREQUEST_H
#define TELEGRAMREQUEST_H

#include <QtNetwork>

class TelegramBot;

class TelegramRequest : public QObject
{
	Q_OBJECT
public:
	enum RequestType
	{
		Unknown,
		SendMessages,
		GetUpdates,
		GetChat,
		GetChatAdministators,
		GetChatMemberCount,
		GetChatMember
	};

	TelegramRequest(QNetworkReply* reply, RequestType requestType, TelegramBot *bot);



	QNetworkReply *reply() const;
	RequestType requestType() const;
	bool ok() const;

private:
	QNetworkReply *m_reply;
	RequestType m_requestType;
	TelegramBot *m_bot;
	bool m_ok;
};

#endif // TELEGRAMREQUEST_H
