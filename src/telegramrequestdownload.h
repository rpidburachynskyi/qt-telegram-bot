#ifndef TELEGRAMREQUESTDOWNLOAD_H
#define TELEGRAMREQUESTDOWNLOAD_H

#include <QNetworkReply>

class TelegramRequestDownload : public QObject
{
	Q_OBJECT
public:
	explicit TelegramRequestDownload(QNetworkReply* reply);

	QNetworkReply *reply() const;

signals:
	void downloaded(const QString &fileName,
					const QByteArray &data);

public slots:

private slots:
	void onReplyFinished();

private:
	QNetworkReply *m_reply;
};

#endif // TELEGRAMREQUESTDOWNLOAD_H
