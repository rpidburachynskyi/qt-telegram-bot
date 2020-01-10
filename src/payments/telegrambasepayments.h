#ifndef TELEGRAMBASEPAYMENTS_H
#define TELEGRAMBASEPAYMENTS_H

#include "../scripts/telegrambase.h"
#include <QList>

class TelegramBasePayments : public TelegramBase
{
public:
	TelegramBasePayments(const bool &isNull);
	TelegramBasePayments(const QJsonObject &json);
};

#endif // TELEGRAMBASEPAYMENTS_H
