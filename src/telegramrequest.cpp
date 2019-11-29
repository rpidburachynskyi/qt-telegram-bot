#include "telegrambot.h"

TelegramRequest::TelegramRequest(QNetworkReply *reply, RequestType requestType, TelegramBot *bot)
	: QObject(bot), m_reply(reply), m_requestType(requestType), m_bot(bot)
{
	connect(m_reply, &QNetworkReply::readyRead, this, &TelegramRequest::onReplyReadyRead);
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

void TelegramRequest::onReplyReadyRead()
{
	switch (m_requestType)
	{
		case Unknown:
			qDebug() << "Unknown request type";
			qDebug() << m_reply->readAll();
			break;
		default: m_bot->onTelegramRequestReply(this); break;
	}
	deleteLater();
}
