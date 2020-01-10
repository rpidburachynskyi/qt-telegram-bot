#ifndef TELEGRAMMASKPOSITION_H
#define TELEGRAMMASKPOSITION_H

#include "telegrambasesticker.h"

class TelegramMaskPosition : public TelegramBaseSticker
{
public:
	TelegramMaskPosition(const QJsonObject &json);

	/// Necessarily
	QString point() const;
	/// Necessarily
	double xShift() const;
	/// Necessarily
	double yShift() const;
	/// Necessarily
	double scale() const;

private:
	QString m_point;
	double m_xShift;
	double m_yShift;
	double m_scale;
};

#endif // TELEGRAMMASKPOSITION_H
