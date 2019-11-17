#ifndef TELEGRAMSHIPPINGADDRESS_H
#define TELEGRAMSHIPPINGADDRESS_H

#include <QJsonObject>

class TelegramShippingAddress
{
public:
	TelegramShippingAddress(const QJsonObject &json);

	/// Necessarily
	QString countryCode() const;
	/// Necessarily
	QString state() const;
	/// Necessarily
	QString city() const;
	/// Necessarily
	QString streetLine1() const;
	/// Necessarily
	QString streetLine2() const;
	/// Necessarily
	QString postCode() const;

private:
	QString m_countryCode;
	QString m_state;
	QString m_city;
	QString m_streetLine1;
	QString m_streetLine2;
	QString m_postCode;
};

#endif // TELEGRAMSHIPPINGADDRESS_H
