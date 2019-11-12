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

	TelegramBot bot("1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4");

	QObject::connect(&bot, &TelegramBot::onMessage, [&bot](const TelegramMessage *message)
	{
		bot.sendAudio(message->chat()->id(), "http://testingrostik.000webhostapp.com/SMS2.mp3");
		bot.sendVideo(message->chat()->id(), "http://testingrostik.000webhostapp.com/videoplay1back.mp4");
	});

	QObject::connect(&bot, &TelegramBot::onBotMessage, [&bot](const TelegramMessage *message)
	{
		TelegramMessage *m = new TelegramMessage(*message);
		QTimer::singleShot(1000, [&bot, m]()
		{
			TelegramInputMedia *media;
			if(m->audio())
				media = new TelegramInputMediaAudio("http://testingrostik.000webhostapp.com/sss.mp3", "EDITED");
			else if(m->video())
				media = new TelegramInputMediaVideo("http://testingrostik.000webhostapp.com/videoplay1back.mp4", "EDITED");

			if(!media)
				return;
			bot.editMessageMedia(m->chat()->id(), m->id(), *media);

			delete media;
		});
	});

	bot.startPolling();

	return a.exec();
}
