#include "telegrammaskposition.h"

TelegramMaskPosition::TelegramMaskPosition(const QJsonObject &json)
{
	m_point = json["point"].toString();
	m_xShift = json["x_shift"].toDouble();
	m_yShift = json["y_shift"].toDouble();
	m_scale = json["scale"].toDouble();
}

QString TelegramMaskPosition::point() const
{
	return m_point;
}

double TelegramMaskPosition::xShift() const
{
	return m_xShift;
}

double TelegramMaskPosition::yShift() const
{
	return m_yShift;
}

double TelegramMaskPosition::scale() const
{
	return m_scale;
}
