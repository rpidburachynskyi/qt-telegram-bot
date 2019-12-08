#include <QCoreApplication>
#include "telegrambot.h"

const QString TOKEN;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);
	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&bot](const TelegramMessage &message)
	{
		QString chatId = message.chat().id();
		QString text = message.from().username() + ": ";
		if(!message.text().isEmpty()) // text message
		{
			text += message.text();
		}else if(!message.photo().isEmpty()) // photo message
		{
			text += "photo (" + QString::number(message.photo().last().fileSize()) + " bytes)";

		}else if(message.video().isNotNull()) // video message
		{
			text += "video (" + QString::number(message.video().fileSize()) + " bytes)";
		}else if(message.audio().isNotNull()) // audio message
		{
			text += "audio (" + QString::number(message.audio().fileSize()) + " bytes)";
		}else if(message.voice().isNotNull()) // voice message
		{
			text += "voice (" + QString::number(message.voice().fileSize()) + " bytes)";
		}else if(message.sticker().isNotNull()) // sticker message
		{
			text += "sticker (" + QString::number(message.sticker().fileSize()) + " bytes)";
		}else if(message.document().isNotNull()) // document message
		{
			text += "document (" + QString::number(message.document().fileSize()) + " bytes)";
		}else if(message.contact().isNotNull()) // contact message
		{
			text += "contact (" + message.contact().firstName() + ")";
		}else if(message.location().isNotNull()) // location message
		{
			text += "location (" + QString::number(message.location().latitude()) + ":" +
					QString::number(message.location().longitute()) + ")";
		}else if(message.poll().isNotNull()) // poll message
		{
			int size = message.poll().options().size();
			TelegramPollOption option = message.poll().options().at(rand() % size);
			text += "poll (Voice please " + option.text() + ")";
		}else if(message.venue().isNotNull()) // venue message
		{
			text += "venue (" + message.venue().address() + ")";
		}else if(!message.newChatPhoto().isEmpty())
		{
			text += "New chat photo";
		}else if(!message.newChatTitle().isEmpty())
		{
			text += "New chat title";
		}else if(!message.newChatMembers().isEmpty())
		{
			text += "New chat member (" + message.newChatMembers().first().username() + ")";
		}else if(!message.leftChatMember().isNotNull())
		{
			text += "Left chat member (" + message.leftChatMember().username() + ")";
		}

		bot.sendMessage(chatId, text);
	});

	bot.startPolling();
	return a.exec();
}
