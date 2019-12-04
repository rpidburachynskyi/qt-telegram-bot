#include "telegramrequestdownload.h"

TelegramRequestDownload::TelegramRequestDownload(QNetworkReply *reply)
	: m_reply(reply)
{
	connect(m_reply, &QNetworkReply::finished, this, &TelegramRequestDownload::onReplyFinished);
}

void TelegramRequestDownload::onReplyFinished()
{
	m_data = m_reply->readAll();
	qDebug() << m_data.size();
	emit downloaded();
}

QNetworkReply *TelegramRequestDownload::reply() const
{
	return m_reply;
}
