#ifndef TELEGRAMLABELEDPRICE_H
#define TELEGRAMLABELEDPRICE_H

#include "telegrambasepayments.h"

class TelegramLabeledPrice : public TelegramBasePayments
{
public:
	TelegramLabeledPrice(const QJsonObject &json);
	TelegramLabeledPrice(const QString &label, const int &amount);

	/// Necessarily
	QString label() const;
	/// Necessarily
	int amount() const;

	QJsonObject toJson() const;

private:
	QString m_label;
	int m_amount;
};

#endif // TELEGRAMLABELEDPRICE_H
