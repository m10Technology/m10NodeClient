#include <QCoreApplication>
#include <client.h>

int main(int argc, char *argv[])
{
    QTextStream input;

    QCoreApplication a(argc, argv);
    Client *client = new Client();
    client->start();
    client->connectToServer("192.168.1.153");

    return a.exec();
}

