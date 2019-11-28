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

#include <unistd.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QList<TelegramStickerSet> sets;

	TelegramBot bot("1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4"); // my token

	QObject::connect(&bot, &TelegramBot::messaged, [&sets, &bot](const TelegramMessage *message)
	{

	});

	QObject::connect(&bot, &TelegramBot::getStickerSetEmitted, [&sets, &bot](const TelegramStickerSet &set)
	{
		qDebug() << "SE" << set.stickers().size();

		sets.append(set);
	});

	QObject::connect(&bot, &TelegramBot::errored, [&sets, &bot]()
	{
		qDebug() << "ERROR";
	});

	bot.setWebhook("https://3e636d09.ngrok.io"); // my ngrok url

	bot.getStickerSet("Apollo");
	bot.getStickerSet("Girl_in_Love");
	return a.exec();
}
