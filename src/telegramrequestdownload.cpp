#include "telegramrequestdownload.h"

TelegramRequestDownload::TelegramRequestDownload(QNetworkReply *reply)
	: m_reply(reply)
{
	connect(m_reply, &QNetworkReply::finished, this, &TelegramRequestDownload::onReplyFinished);
}

void TelegramRequestDownload::onReplyFinished()
{
	QByteArray data = m_reply->readAll();

	emit downloaded(m_reply->url().fileName(), data);

	deleteLater();
}

QNetworkReply *TelegramRequestDownload::reply() const
{
	return m_reply;
}
