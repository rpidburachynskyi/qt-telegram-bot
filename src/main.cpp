#include <QCoreApplication>

#include "telegrambot.h"
#include "types/telegrammessage.h"
#include "types/telegramchat.h"
#include "types/telegramaudio.h"
#include "types/telegramdocument.h"
#include "types/telegramvideo.h"
#include "types/telegramcontact.h"
#include "types/telegrammessageentity.h"
#include "types/telegraminlinekeyboardmarkup.h"
#include "types/telegramuser.h"
#include "types/telegramforcereply.h"
#include "types/telegramreplykeyboardmarkup.h"
#include "types/telegraminputmediaaudio.h"
#include "types/telegraminputmediavideo.h"
#include "types/telegraminputmediaanimation.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TelegramBot bot("1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4"); // my token

	QObject::connect(&bot, &TelegramBot::onMessage, [&bot](const TelegramMessage *message)
	{
		QString chatId = message->chat()->id();

		bot.sendMessage(chatId, "I am from Ukraine");
	});

	QObject::connect(&bot, &TelegramBot::onBotMessage, [&bot](const TelegramMessage *message)
	{
		if(message->text() != "I am from Ukraine")
			return;
		std::shared_ptr<char> sp(new char[8]);
		sp.get()[0] = 0xF0;
		sp.get()[1] = 0x9F;
		sp.get()[2] = 0x87;
		sp.get()[3] = 0xBA;
		sp.get()[4] = 0xF0;
		sp.get()[5] = 0x9F;
		sp.get()[6] = 0x87;
		sp.get()[7] = 0xA6;
		for(int i = 0; i < 10; i++)
		bot.sendMessage(message->chat()->id(), QString::fromUtf8(sp.get(), 8));
	});

	bot.setWebhook("https://cf22735c.ngrok.io"); // my ngrok url
	return a.exec();
}
