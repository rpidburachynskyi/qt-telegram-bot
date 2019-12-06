#ifndef TELEGRAMINPUTTEXTMESSAGECONTENT_H
#define TELEGRAMINPUTTEXTMESSAGECONTENT_H

#include "telegraminputmessagecontent.h"

class TelegramInputTextMessageContent : public TelegramInputMessageContent
{
public:
	TelegramInputTextMessageContent(const QString &messageText,
									const QString &parseMode = "",
									const bool &disableWebPagePreview = false);
	TelegramInputMessageContent* clone() const override;

	/// Necessarily
	inline void setMessageText(const QString &messageText) {
		m_messageText = messageText;
	}
	inline QString messageText() const {
		return m_messageText;
	}
	/// Optional
	inline void setParseMode(const QString &parseMode) {
		m_parseMode = parseMode;
	}
	inline QString parseMode() const {
		return m_parseMode;
	}
	/// Optional
	inline void setDisableWebPagePreview(const bool &disableWebPagePreview) {
		m_disableWebPagePreview = disableWebPagePreview;
	}
	inline bool disableWebPagePreview() const {
		return m_disableWebPagePreview;
	}

	QJsonObject toJson() const override;

private:
	QString m_messageText;
	QString m_parseMode;
	bool m_disableWebPagePreview;
};

#endif // TELEGRAMINPUTTEXTMESSAGECONTENT_H
