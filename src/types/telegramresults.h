#ifndef TELEGRAMRESULTS_H
#define TELEGRAMRESULTS_H


#include <QList>
#include <QJsonArray>

class TelegramResult;
class TelegramUpdate;

class TelegramResults
{
public:
	TelegramResults(const QJsonArray &array);
	~TelegramResults();

	QList<TelegramResult *> results() const;

	static TelegramResult *resultFromJSOM(const QJsonObject &json);

private:
	QList<TelegramResult *> m_results;
};

#endif // TELEGRAMRESULTS_H
