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
		if(message->audio())
		{
			bot.sendMessage(message->chat()->id(), "Audio");
		}else if(message->video())
		{
			bot.sendMessage(message->chat()->id(), "Video");
		}else if(message->document())
		{
			bot.sendMessage(message->chat()->id(), "Document");
		}else if(message->voice())
		{
			bot.sendMessage(message->chat()->id(), "Voice");
		}else if(message->sticker())
		{
			bot.sendMessage(message->chat()->id(), "Sticker");
		}else if(message->newChatMembers().size() > 0)
		{
			bot.sendMessage(message->chat()->id(), "New member");
		}else if(message->leftChatMember())
		{
			bot.sendMessage(message->chat()->id(), "Left member");
		}else if(!message->newChatTitle().isEmpty())
		{
			bot.sendMessage(message->chat()->id(), "New chat title");
		}else if(message->pinnedMessage())
		{
			bot.sendMessage(message->chat()->id(), "Pinned message");
		}else if(!message->text().isEmpty())
		{
			bot.sendMessage(message->chat()->id(), "Text message");
		}
	});

	bot.setWebhook("https://85005063.ngrok.io"); // my ngrok url
	return a.exec();
}
