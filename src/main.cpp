#include <QCoreApplication>

#include "telegrambot.h"
#include "inline/telegraminlinequeryresultarticle.h"
#include "inline/telegraminlinequeryresultphoto.h"
#include "inline/telegraminputtextmessagecontent.h"
#include "inline/telegraminlinequeryresultgif.h"
#include "inline/telegraminputlocationmessagecontent.h"

const QString NGROK_URL = "https://59524f8c.ngrok.io";
const QString TOKEN = "1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4";

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList badWords = {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::inlineQueried, [&bot](const TelegramInlineQuery &inlineQuery)
	{
		qDebug() << inlineQuery.query();
		TelegramInputTextMessageContent text("My text23123");
		TelegramInputTextMessageContent text2("My text2");
		TelegramInlineQueryResultArticle article("ROSTIK", "My title122222", &text);
		TelegramInlineQueryResultArticle article2("ROSTIK2", "My title2", &text2);
		TelegramInlineQueryResultPhoto photo("bid", "https://petapixel.com/assets/uploads/2019/06/manipulatedelephant-800x534.jpg",
											 "https://petapixel.com/assets/uploads/2019/06/manipulatedelephant-800x534.jpg");
		photo.setInputMessageContent(&text);

		TelegramInlineQueryResultGif gif("!!", "https://thumbs.gfycat.com/MellowIgnorantDipper-size_restricted.gif",
										 "https://thumbs.gfycat.com/MellowIgnorantDipper-size_restricted.gif");

		gif.setInputMessageContent(&text);

		TelegramInputLocationMessageContent loc (44.353, 44.343);
		gif.setInputMessageContent(&loc);
		bot.answerInlineQuery(inlineQuery.id(), {&article, &article2, &photo, &gif});
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	//bot.deleteWebhook();
	//bot.startPolling();
	return a.exec();
}
