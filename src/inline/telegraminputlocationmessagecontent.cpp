#include "telegraminputlocationmessagecontent.h"

TelegramInputLocationMessageContent::
TelegramInputLocationMessageContent(const double &latitude,
									const double &longitute,
									const int &livePeriod)
	: m_latitude(latitude),
	  m_longitute(longitute),
	  m_livePeriod(livePeriod)
{ }

QJsonObject TelegramInputLocationMessageContent::toJson() const
{
	QJsonObject json;

	json["latitude"] = m_latitude;
	json["longitude"] = m_longitute;
	if(m_livePeriod >= 60 && m_livePeriod <= 86400)
		json["live_period"] = m_livePeriod;

	return json;
}
