#include "telegrambot.h"

TelegramRequest::TelegramRequest(QNetworkReply *reply, RequestType requestType, TelegramBot *bot)
	: QObject(bot), m_reply(reply), m_requestType(requestType), m_bot(bot)
{
	connect(m_reply, &QNetworkReply::readyRead, [this]()
	{
		switch (m_requestType)
		{
			case Unknown: qDebug() << "Unknown request type"; break;
			case GetUpdates: m_bot->onGetUpdates(this); break;
			case GetChat: m_bot->onGetChat(this); break;
			case GetChatAdministators: m_bot->onGetChatAdministators(this); break;
			case GetChatMemberCount: m_bot->onGetChatMemberCount(this); break;
			case GetChatMember: m_bot->onGetChatMember(this); break;
			case GetStickerSet: m_bot->onGetStickerSet(this); break;
			default: m_bot->onTelegramRequestReply(this); break;
		}
		deleteLater();
	});
}

QNetworkReply *TelegramRequest::reply() const
{
	return m_reply;
}

TelegramRequest::RequestType TelegramRequest::requestType() const
{
	return m_requestType;
}

bool TelegramRequest::ok() const
{
	return m_ok;
}
