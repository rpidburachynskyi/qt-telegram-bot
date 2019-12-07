#include "telegramresults.h"
#include "telegramupdate.h"

#include <QJsonArray>
#include <QJsonObject>

TelegramResults::TelegramResults(const QJsonArray &array)
{
	for(auto item : array)
	{
		QJsonObject json = item.toObject();
		TelegramResult result(json);

		m_results.append(result);
	}
}

QList<TelegramResult> TelegramResults::results() const
{
	return m_results;
}
