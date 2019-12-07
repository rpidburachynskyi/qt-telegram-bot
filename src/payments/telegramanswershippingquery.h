#ifndef TELEGRAMANSWERSHIPPINGQUERY_H
#define TELEGRAMANSWERSHIPPINGQUERY_H

#include "telegramshipingoption.h"
#include "telegrambasepayments.h"

class TelegramAnswerShippingQuery : public TelegramBasePayments
{
public:
	TelegramAnswerShippingQuery(const QJsonObject &json);

	// Necessarily
	QString shippingQueryId() const;
	// Necessarily
	bool ok() const;
	// Optional
	QList<TelegramShipingOption> options() const;
	// Optional
	QString errorMessage() const;

private:
	QString m_shippingQueryId;
	bool m_ok;
	QList<TelegramShipingOption> m_options;
	QString m_errorMessage;
};

#endif // TELEGRAMANSWERSHIPPINGQUERY_H
