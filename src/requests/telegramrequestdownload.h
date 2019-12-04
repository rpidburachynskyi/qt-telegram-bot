#ifndef TELEGRAMREQUESTDOWNLOAD_H
#define TELEGRAMREQUESTDOWNLOAD_H

#include <QNetworkReply>

class TelegramRequestDownload : public QObject
{
	Q_OBJECT
public:
	explicit TelegramRequestDownload(QNetworkReply* reply);

	QNetworkReply *reply() const;

	QByteArray data() const {
		return m_data;
	}

signals:
	void downloaded();

public slots:

private slots:
	void onReplyFinished();

private:
	QNetworkReply *m_reply;
	QByteArray m_data;
};

#endif // TELEGRAMREQUESTDOWNLOAD_H
