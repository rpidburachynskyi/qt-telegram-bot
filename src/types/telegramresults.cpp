#include "telegramresults.h"
#include "telegramupdate.h"

#include <QJsonObject>

TelegramResults::TelegramResults(const QJsonArray &array)
{
	for(auto item : array)
	{
		QJsonObject json = item.toObject();
		TelegramResult *result = resultFromJSOM(json);

		m_results.append(result);
	}
}

TelegramResults::~TelegramResults()
{
	if(!m_results.isEmpty())
	{
		for(auto result : m_results)
		{
			delete result;
		}
	}
}

QList<TelegramResult *> TelegramResults::results() const
{
	return m_results;
}

TelegramResult *TelegramResults::resultFromJSOM(const QJsonObject &json)
{
	TelegramResult *result = nullptr;
	if(json.contains("update_id"))
		result = new TelegramUpdate(json);
	return result;
}
