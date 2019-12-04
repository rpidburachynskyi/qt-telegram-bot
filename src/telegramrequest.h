#ifndef TELEGRAMREQUEST_H
#define TELEGRAMREQUEST_H

#include <QtNetwork>
#include "types/telegrammessage.h"
#include "types/telegramfile.h"

class TelegramBot;

class TelegramRequest : public QObject
{
	Q_OBJECT

	friend class TelegramBot;
public:
	enum RequestType
	{
		Unknown,
		SendMessages,
		GetUpdates,
		GetChat,
		GetChatAdministators,
		GetChatMemberCount,
		GetChatMember,
		GetFile,
		GetMe,
		GetStickerSet
	};

	TelegramRequest(QNetworkReply* reply, RequestType requestType, QObject *parent = nullptr);
	~TelegramRequest() {qDebug() << "DEL";}


	inline bool ok() const {
		return m_ok;
	}
	inline QJsonObject result() const {
		qDebug() << "addr2" << &(*this);
		qDebug() << m_results.size();
		if(m_results.isEmpty())
			throw std::runtime_error("Take result without ok");
		return m_results.first();
	}

	inline TelegramMessage* message() {
		TelegramMessage* msg = new TelegramMessage(m_results.first());
		return msg;
	}

	inline TelegramFile* file() {
		TelegramFile* msg = new TelegramFile(m_results.first());
		return msg;
	}

signals:
	void finished(const bool &ok);

private slots:
	void onReplyReadyRead();

private:
	QNetworkReply *m_reply;
	QByteArray m_data;
	RequestType m_requestType;
	QList<QJsonObject> m_results;
	bool m_ok;
};

#endif // TELEGRAMREQUEST_H
