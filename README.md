# Telegram Bot API for Qt5
---
# How to include

Static build of the project is used for inclusion. To do this, simply include everything from the "src" folder in your project. 

# How to use
To create a bot, you must include a header file in the project.

```qmake
#include "src/telegrambot.h"
```
The next step is the initialization, it is done with the token you received from @BotFather

```qmake
TelegramBot bot(TOKEN);
```
There are two ways to get updates, you can do this.

* Use the queries that will receive updates
```qmake
bot.startPolling();
```

* With the server and the address to which the updates will come
```qmake
bot.setWebhook(TelegramBot::createListenServer(PORT), YOUR_URL);
```
* You can process updates using the "message" signal.

```qmake
QObject::connect(&bot, &TelegramBot::messaged, [&bot](const TelegramMessage *message)
{
     qDebug() << "New message";
});
```

* You must use the sendMessage method to send messages
```qmake
bot.sendMessage(message->chat()->id(), "My first message");
```
# Full code

```qmake
#include <QCoreApplication>

#include "telegrambot.h"

const QString NGROK_URL = "https://76e10852.ngrok.io"; // ngrok for example
const QString TOKEN;

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::messaged, [&bot](const TelegramMessage *message)
	{
		bot.sendMessage(message->chat()->id(), "My first message");
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	return a.exec();
}

```

	
>>>>>>> Update README
