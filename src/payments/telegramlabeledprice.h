#ifndef TELEGRAMLABELEDPRICE_H
#define TELEGRAMLABELEDPRICE_H

#include <QJsonObject>

class TelegramLabeledPrice
{
public:
	TelegramLabeledPrice(const QJsonObject &json);

	/// Necessarily
	QString label() const;
	/// Necessarily
	int amount() const;

private:
	QString m_label;
	int m_amount;
};

#endif // TELEGRAMLABELEDPRICE_H
