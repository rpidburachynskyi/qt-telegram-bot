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
#include "types/telegramreplykeyboardremove.h"
#include "types/telegramchatphoto.h"
#include "types/telegramphotosize.h"

const QString TOKEN = "1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4";

int exampleDeleteBadWordsText(QCoreApplication *a);
int exampleSaveAllSendedPhoto(QCoreApplication *a);

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	return exampleSaveAllSendedPhoto(&a);
}

int exampleDeleteBadWordsText(QCoreApplication *a)
{
	const QString NGROK_URL = "https://096d8075.ngrok.io";
	QStringList badWords =  {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&badWords, &bot](const TelegramMessage *message)
	{
		QString text = message->text();
		QStringList words = text.split(' ');
		bool flag = false;

		for(QString word : words)
		{
			if(badWords.contains(word))
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			bot.deleteMessage(message->chat()->id(), message->id());
		}
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	return a->exec();
}

int exampleSaveAllSendedPhoto(QCoreApplication *a)
{
	const QString NGROK_URL = "https://096d8075.ngrok.io";
	QStringList badWords =  {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&badWords, &bot](const TelegramMessage *message)
	{
		if(message->photo().isEmpty())
			return;
		qDebug() << "PHOTO";
		bot.getFile(message->photo().last()->fileId());
		qDebug() << message->photo().last()->fileId();
	});

	QObject::connect(&bot, &TelegramBot::getFileReady, [&bot](const TelegramFile &file)
	{
		bot.downloadFile(file.filePath());
	});

	QObject::connect(&bot, &TelegramBot::fileDownloaded, [](const QString &fileName, const QByteArray &data)
	{
		qDebug() << "D";
		static int n = 0;
		QString ext = fileName.right(fileName.lastIndexOf("."));
		QString name = "Q:/Temp/File_" + QString::number(n++) + ext;
		QFile f(name);
		if(!f.open(QIODevice::WriteOnly))
			return;
		f.write(data);
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	return a->exec();
}

