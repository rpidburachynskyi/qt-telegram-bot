#ifndef TELEGRAMINVOICE_H
#define TELEGRAMINVOICE_H

#include "telegrambasepayments.h"

class TelegramInvoice : public TelegramBasePayments
{
public:
	TelegramInvoice(const QJsonObject &json);

	QString title() const;
	QString description() const;
	QString startParameter() const;
	QString currency() const;
	int totalAmount() const;

private:
	QString m_title;
	QString m_description;
	QString m_startParameter;
	QString m_currency;
	int m_totalAmount;
};

#endif // TELEGRAMINVOICE_H
