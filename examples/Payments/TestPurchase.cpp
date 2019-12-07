#include <QCoreApplication>
#include "telegrambot.h"

const QString NGROK_URL = "https://***.ngrok.io";
const QString TOKEN = "";
const QString PROVIDER_TOKEN = ":TEST:";

const bool NEED_NAME_ON_ORDER = true;
const bool NEED_PHONE_NUMBER_ON_ORDER = true;
const bool NEED_EMAIL_ON_ORDER = true;
const bool NEED_SHIPPING_ADDRESS_ON_ORDER = true;

static TelegramBot bot(TOKEN);
static int countOfShirts = 2;

void onMessaged(const TelegramMessage *message);
void onPreCheckoutQuery(const TelegramPreCheckoutQuery &query);

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QStringList badWords = {"Hello", "Rostik", "Tawer"};

	QObject::connect(&bot, &TelegramBot::messaged, &onMessaged);
	QObject::connect(&bot, &TelegramBot::preCheckoutQueried, &onPreCheckoutQuery);

	bot.setWebhook(TelegramBot::createListenServer(3000), NGROK_URL);
	return a.exec();
}

void onMessagedText(const TelegramMessage *message)
{
	if(message->text() == "ORDER")
	{
		const QString shirtUrl = "https://images-na.ssl-images-amazon.com/images/I/410el0B7L6L.jpg";
		TelegramLabeledPrice price("Shirt", 24000), delivery("Delivery", 5000);
		bot.sendInvoice(message->chat()->id(),
						"Best shirt",
						"Best shirt in the world",
						"PAYLOAD",
						PROVIDER_TOKEN,
						"START",
						"UAH",
		{price, delivery},
						"",
						shirtUrl,
						-1,
						-1,
						-1,
						NEED_NAME_ON_ORDER,
						NEED_PHONE_NUMBER_ON_ORDER,
						NEED_EMAIL_ON_ORDER,
						NEED_SHIPPING_ADDRESS_ON_ORDER,
						true,
						true,
						false);
	}
}

void onMessaged(const TelegramMessage *message)
{
	if(!message->text().isEmpty())
		onMessagedText(message);
	if(message->successfulPayment())
	{
		qDebug() << "Order from: " << message->successfulPayment()->orderInfo().name();
	}
}

void onPreCheckoutQuery(const TelegramPreCheckoutQuery &query)
{
	qDebug() << "ONPRE";
	if(countOfShirts-- > 0)
		bot.answerPreCheckoutQuery(query.id(), true);
	else bot.answerPreCheckoutQuery(query.id(), false, "Shirts is over");
}
