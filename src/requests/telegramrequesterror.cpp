#include "telegramrequesterror.h"
#include <QDebug>

TelegramRequestError::TelegramRequestError()
{ }

TelegramRequestError::TelegramRequestError(const QJsonObject &json)
{
	qDebug() << json;
	m_errorCode = json["error_code"].toInt();
	m_description = json["description"].toString();
}
