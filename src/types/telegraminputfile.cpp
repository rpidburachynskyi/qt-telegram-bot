#include "telegraminputfile.h"

TelegramInputFile::TelegramInputFile(const QString &value,
									 const TelegramInputFile::InputType &inputType)
{
	m_value = value;
	m_inputType = inputType;
}

QString TelegramInputFile::value() const
{
	return m_value;
}

TelegramInputFile::InputType TelegramInputFile::inputType() const
{
	return m_inputType;
}
