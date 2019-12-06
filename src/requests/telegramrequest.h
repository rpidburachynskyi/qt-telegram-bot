#ifndef TELEGRAMREQUEST_H
#define TELEGRAMREQUEST_H

#include "telegramrequesterror.h"
#include "types/telegrammessage.h"
#include "types/telegramfile.h"
#include <QtNetwork>

class TelegramBot;

class TelegramRequest : public QObject
{
	Q_OBJECT

	friend class TelegramBot;

	explicit TelegramRequest(QNetworkReply* reply);
	TelegramRequest(const TelegramRequest &) = delete;
	~TelegramRequest();

	TelegramRequest& operator=(const TelegramRequest&) = delete;

public:

	inline bool ok() const { return m_ok; }
	QJsonObject result() const;
	inline const QList<QJsonObject> results() const {
		return m_results;
	}
	TelegramRequestError error() const;
	inline const TelegramMessage* message() {
		return takeInRubbish(new TelegramMessage(result()));
	}
	inline const TelegramFile* file() {
		return takeInRubbish(new TelegramFile(result()));
	}

signals:
	void finished(const bool &ok);
	void errored(const TelegramRequestError &error);

private slots:
	void onReplyReadyRead();

private:

	QList<void *> m_rubbish;
	QNetworkReply *m_reply;
	QByteArray m_data;
	QList<QJsonObject> m_results;
	TelegramRequestError m_error;
	bool m_ok;

	template<class T>
	inline const T* takeInRubbish(const T *t)
	{
		m_rubbish.append(&t);
		return t;
	}
};

#endif // TELEGRAMREQUEST_H
