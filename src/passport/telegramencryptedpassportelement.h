#ifndef TELEGRAMENCRYPTEDPASSPORTELEMENT_H
#define TELEGRAMENCRYPTEDPASSPORTELEMENT_H

#include <QJsonObject>
#include <QList>

class TelegramPassportFile;

class TelegramEncryptedPassportElement
{
public:
	TelegramEncryptedPassportElement(const QJsonObject &json);

	/// Necessarily
	QString type() const;
	/// Optional
	QString data() const;
	/// Optional
	QString phoneNumber() const;
	/// Optional
	QString email() const;
	/// Optional
	QList<const TelegramPassportFile *> files() const;
	/// Optional
	TelegramPassportFile *frontSide() const;
	/// Optional
	TelegramPassportFile *reverseSide() const;
	/// Optional
	TelegramPassportFile *selfie() const;
	/// Optional
	QList<const TelegramPassportFile *> translation() const;
	/// Necessarily
	QString hash() const;

private:
	QString m_type;
	QString m_data;
	QString m_phoneNumber;
	QString m_email;
	QList<const TelegramPassportFile *> m_files;
	TelegramPassportFile *m_frontSide;
	TelegramPassportFile *m_reverseSide;
	TelegramPassportFile *m_selfie;
	QList<const TelegramPassportFile *> m_translation;
	QString m_hash;
};

#endif // TELEGRAMENCRYPTEDPASSPORTELEMENT_H
