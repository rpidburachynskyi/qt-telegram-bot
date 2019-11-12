#ifndef TELEGRAMKEYBOARDBUTTON_H
#define TELEGRAMKEYBOARDBUTTON_H

#include <QJsonObject>

class TelegramKeyboardButton
{
public:
	TelegramKeyboardButton(const QJsonObject &json);
	TelegramKeyboardButton(const QString &text,
						   const bool &requestContact = false,
						   const bool &requestLocation = false);

	QString text() const;
	bool requestContact() const;
	bool requestLocation() const;

	QJsonObject toJson() const;

private:
	QString m_text;
	bool m_requestContact;
	bool m_requestLocation;
};

#endif // TELEGRAMKEYBOARDBUTTON_H
