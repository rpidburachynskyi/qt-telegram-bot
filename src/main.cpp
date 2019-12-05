#include <QCoreApplication>

#include "telegrambot.h"

const QString NGROK_URL = "https://76e10852.ngrok.io";
const QString TOKEN = "1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4";

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList badWords = {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&bot](const TelegramMessage *message)
	{
		auto r1 = bot.sendMessage(message->chat()->id(), "1");
		TelegramInputFile file = TelegramInputFile::fromFilePath("Q:\\1.png");
		auto r2 = bot.sendPhoto(message->chat()->id(), file);

		QObject::connect(r1, &TelegramRequest::finished, []()
		{
			qDebug() << "MESSAGE SENDED";
		});
		QObject::connect(r2, &TelegramRequest::finished, [&bot, r2]()
		{
			auto r22 = bot.getFile(r2->message()->photo().first()->fileId());
			QObject::connect(r22, &TelegramRequest::finished, [&bot, r22]()
			{
				auto r3 = bot.downloadFile(r22->file()->filePath());
				qDebug() << r22->file()->filePath();
				QObject::connect(r3, &TelegramRequestDownload::downloaded, [r3]()
				{
					qDebug() << "DOWNLOADED";
					QFile file("Q:\\3.png");
					file.open(QIODevice::WriteOnly);
					file.write(r3->data());
				});
			});
		});
	});

	//bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	bot.deleteWebhook();
	bot.startPolling();
	return a.exec();
}
