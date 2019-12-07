#ifndef TELEGRAMSHIPINGOPTION_H
#define TELEGRAMSHIPINGOPTION_H

#include "telegramlabeledprice.h"

class TelegramShipingOption : public TelegramBasePayments
{
public:
	TelegramShipingOption(const QJsonObject &json);

	/// Necessarily
	QString id() const;
	/// Necessarily
	void setId(const QString &id);

	/// Necessarily
	QString title() const;
	/// Necessarily
	void setTitle(const QString &title);

	/// Necessarily
	QList<TelegramLabeledPrice> prices() const;
	/// Necessarily
	void setPrices(const QList<TelegramLabeledPrice> &prices);

private:
	QString m_id;
	QString m_title;
	QList<TelegramLabeledPrice> m_prices;
};

#endif // TELEGRAMSHIPINGOPTION_H
