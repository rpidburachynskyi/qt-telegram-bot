#ifndef TELEGRAMINPUTLOCATIONMESSAGECONTENT_H
#define TELEGRAMINPUTLOCATIONMESSAGECONTENT_H

#include "telegraminputmessagecontent.h"

class TelegramInputLocationMessageContent : public TelegramInputMessageContent
{
public:
	TelegramInputLocationMessageContent(const double &latitude,
										const double &longitute,
										const int &livePeriod = 86400);

	double latitude() const { return m_latitude; }
	void setLatitude(double latitude) { m_latitude = latitude; }

	double longitute() const { return m_longitute; }
	void setLongitute(double longitute) { m_longitute = longitute; }

	int livePeriod() const { return m_livePeriod; }
	void setLivePeriod(int livePeriod) { m_livePeriod = livePeriod;}

	TelegramInputMessageContent *clone() const override {
		return new TelegramInputLocationMessageContent(*this);
	}
	QJsonObject toJson() const override;

private:
	double m_latitude;
	double m_longitute;
	int m_livePeriod;
};

#endif // TELEGRAMINPUTLOCATIONMESSAGECONTENT_H
