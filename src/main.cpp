#include <QCoreApplication>

#include "telegrambot.h"

const QString NGROK_URL = "https://1defa72d.ngrok.io";
const QString TOKEN = "1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4";

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList badWords =  {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&bot](const TelegramMessage *message)
	{
		bot.sendVideoByPath(message->chat()->id(), "D:\\Downloads\\SampleVideo_1280x720_1mb.mp4");
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	return a.exec();
}
