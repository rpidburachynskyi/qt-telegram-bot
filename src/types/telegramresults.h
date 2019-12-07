#ifndef TELEGRAMRESULTS_H
#define TELEGRAMRESULTS_H

#include "telegramresult.h"
#include <QList>

class TelegramResults
{
public:
	TelegramResults(const QJsonArray &array);

	QList<TelegramResult> results() const;

private:
	QList<TelegramResult> m_results;
};

#endif // TELEGRAMRESULTS_H
