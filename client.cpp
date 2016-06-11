#include "client.h"

Client::Client()
{
    socket = new QTcpSocket();
}

void Client::run()
{
    qDebug() << "Running";
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
    exec();
}

void Client::connectToServer(QString ipAddress)
{
    socket->connectToHost(ipAddress,8085);
    qDebug() << "Connected and listening for input from server..." << endl;
}

void Client::readyRead()
{
     qDebug() << "Data Recieved from Server" << endl;
    //Take in data and store in memory
    QByteArray dataIn = socket->readAll();
    qDebug() << "Data in" << dataIn << endl;
    commands.append(dataIn);

    //Do something with data
    if(dataIn == "getIP"){
      //  QByteArray myIP = getIP();
        //socket->write(myIP);
    }
    commandExecutor[commandCounter] = new CommandThread();
    commandExecutor[commandCounter]->start();
    qDebug() << "Giving " << dataIn;
    commandExecutor[commandCounter]->giveCommand(dataIn);
    commandCounter++;

}

void Client::disconnected()
{
    socket->deleteLater();
    return;
}


