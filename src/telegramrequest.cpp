#include "telegrambot.h"

TelegramRequest::TelegramRequest(QNetworkReply *reply,
								 RequestType requestType,
								 QObject *parent)
	: QObject(nullptr), m_reply(reply), m_requestType(requestType)
{
	connect(m_reply, &QNetworkReply::readyRead, this, &TelegramRequest::onReplyReadyRead);
}

void TelegramRequest::onReplyReadyRead()
{
	m_data = m_reply->readAll();

	QJsonDocument doc = QJsonDocument::fromJson(m_data);

	QJsonObject json = doc.object();
	m_ok = json["ok"].toBool();

	if(json["result"].isObject())
	{
		m_results = { json["result"].toObject() };
		qDebug() << "addr" << &(*this);
	}else
	{
		QJsonArray results = json["result"].toArray();
		for(QJsonValueRef value : results)
		{
			QJsonObject result = value.toObject();
			m_results.append(result);
		}
	}

	emit finished(m_ok);
}
