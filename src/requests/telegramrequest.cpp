#include "telegrambot.h"

TelegramRequest::TelegramRequest(QNetworkReply *reply)
	: m_reply(reply)
{
	connect(m_reply, &QNetworkReply::readyRead, this, &TelegramRequest::onReplyReadyRead);
}

TelegramRequest::~TelegramRequest()
{
	qDeleteAll(m_rubbish);

	delete m_reply;
}

QJsonObject TelegramRequest::result() const
{
	if(m_results.isEmpty())
		throw std::runtime_error("Take result without ok");
	return m_results.first();
}

TelegramRequestError TelegramRequest::error() const
{
	if(m_ok)
		throw std::runtime_error("Take error when ok");
	return m_error;
}

void TelegramRequest::onReplyReadyRead()
{
	m_data = m_reply->readAll();

	QJsonDocument doc = QJsonDocument::fromJson(m_data);

	QJsonObject json = doc.object();
	m_ok = json["ok"].toBool();

	if(m_ok)
	{
		if(json["result"].isObject())
		{
			m_results = { json["result"].toObject() };
		}else
		{
			QJsonArray results = json["result"].toArray();
			for(QJsonValueRef value : results)
			{
				QJsonObject result = value.toObject();
				m_results.append(result);
			}
		}
	}else
	{
		m_error = TelegramRequestError(json);
	}
	emit finished(m_ok);
}
