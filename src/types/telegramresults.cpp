#include "telegramresults.h"
#include "telegramupdate.h"

#include <QJsonObject>


TelegramResults::TelegramResults(const QJsonArray &array)
{
	for(auto item : array)
	{
		TelegramResult *result;
		QJsonObject json = item.toObject();

		if(json.contains("update_id"))
			result = new TelegramUpdate(json);

		m_results.append(result);
	}
}

QList<TelegramResult *> TelegramResults::results() const
{
	return m_results;
}
