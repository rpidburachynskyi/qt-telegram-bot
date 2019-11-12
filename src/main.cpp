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

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TelegramBot bot("1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4");

	QObject::connect(&bot, &TelegramBot::onMessage, [&bot](const TelegramMessage *message)
	{
		TelegramKeyboardButton k1("R"), k2("T");
		TelegramReplyKeyboardMarkup keyboard({k1, k2}, false, true);

		bot.sendMessage(message->chat()->id(), "123", &keyboard);
	});


	QTimer timer;
	timer.setInterval(1000);
	timer.start(100);
	QObject::connect(&timer, &QTimer::timeout, [&bot](){bot.getUpdates();});

	return a.exec();
}
