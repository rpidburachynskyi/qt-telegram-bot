#include "telegramrequesterror.h"

TelegramRequestError::TelegramRequestError()
{ }

TelegramRequestError::TelegramRequestError(const QJsonObject &json)
{
	m_errorCode = json["error_code"].toInt();
	m_description = json["description"].toString();
}
