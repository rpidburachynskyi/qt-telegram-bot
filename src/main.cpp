#include <QCoreApplication>

#include "telegrambot.h"
#include "inline/telegraminlinequeryresultarticle.h"
#include "inline/telegraminlinequeryresultphoto.h"
#include "inline/telegraminputtextmessagecontent.h"
#include "inline/telegraminlinequeryresultgif.h"
#include "inline/telegraminputlocationmessagecontent.h"
#include "inline/telegraminlinequeryresultvideo.h"
#include "inline/telegraminlinequeryresultaudio.h"
#include "inline/telegraminlinequeryresultvoice.h"
#include "inline/telegraminlinequeryresultdocument.h"
#include "inline/telegraminlinequeryresultlocation.h"
#include "inline/telegraminlinequeryresultvenue.h"
#include "inline/telegraminlinequeryresultcontact.h"

const QString NGROK_URL = "https://e0fe6a1a.ngrok.io";
const QString TOKEN = "1066331366:AAHGiv80O-QJwo4f8ZI2Ma5j03GjbZUX7H4";

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList badWords = {"Hello", "Rostik", "Tawer"};

	TelegramBot bot(TOKEN);

	QObject::connect(&bot, &TelegramBot::inlineQueried, [&bot](const TelegramInlineQuery &inlineQuery)
	{
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

		TelegramInlineQueryResultVideo video("ss", "http://testingrostik.000webhostapp.com/videoplay1back.mp4",
											 "https://petapixel.com/assets/uploads/2019/06/manipulatedelephant-800x534.jpg", "Best video");

		TelegramInlineQueryResultAudio audio("aa", "http://testingrostik.000webhostapp.com/SMS2.mp3", "aaa");

		TelegramInlineQueryResultVoice voice("vv", "http://testingrostik.000webhostapp.com/SMS2.mp3", "Haha");

		TelegramInlineQueryResultDocument doc("S", "http://testingrostik.000webhostapp.com/Rostik.css",
											  "SSS", TelegramInlineQueryResultDocument::PDF);

		TelegramInlineQueryResultLocation loc1("L", 33, 22, "My loc");

		TelegramInlineQueryResultVenue ven("ven", 2.28, 13.37, "Rostik", "UA");

		TelegramInlineQueryResultContact con("cc", "+38098888888", "Rostik");
		con.setThumbUrl("https://petapixel.com/assets/uploads/2019/06/manipulatedelephant-800x534.jpg");
		bot.answerInlineQuery(inlineQuery.id(), {&con, &ven, &loc1, &doc, &article, &article2, &photo, &gif, &video, &audio, &voice});
	});

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	//bot.deleteWebhook();
	//bot.startPolling();
	return a.exec();
}
