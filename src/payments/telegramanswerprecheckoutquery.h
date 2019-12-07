#ifndef TELEGRAMANSWERPRECHECKOUTQUERY_H
#define TELEGRAMANSWERPRECHECKOUTQUERY_H

#include "telegrambasepayments.h"

class TelegramAnswerPreCheckoutQuery : public TelegramBasePayments
{
public:
	TelegramAnswerPreCheckoutQuery(const QJsonObject &json);

	// Necessarily
	QString preCheckoutQueryId() const;
	// Necessarily
	bool ok() const;
	// Optional
	QString errorMessage() const;

private:
	QString m_preCheckoutQueryId;
	bool m_ok;
	QString m_errorMessage;
};

#endif // TELEGRAMANSWERPRECHECKOUTQUERY_H
