#ifndef TELEGRAMINPUTFILE_H
#define TELEGRAMINPUTFILE_H

#include <QJsonObject>

class TelegramInputFile
{
public:
	enum InputType
	{
		Id,
		Url,
		FilePath
	};

	TelegramInputFile(const QString &value,
					  const InputType &inputType);

	QString value() const;
	InputType inputType() const;

	inline static TelegramInputFile fromFilePath(const QString &filePath) {
		return TelegramInputFile(filePath, FilePath);
	}
	inline static TelegramInputFile fromFileId(const QString &fileId) {
		return TelegramInputFile(fileId, Id);
	}
	inline static TelegramInputFile fromFileUrl(const QString &url) {
		return TelegramInputFile(url, Url);
	}

private:
	QString m_value;
	InputType m_inputType;
};

#endif // TELEGRAMINPUTFILE_H
