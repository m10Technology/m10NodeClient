#include "commandthread.h"


void CommandThread::run(){
    //Starts new thread
    qDebug() << "New thread started for execution of command";
}

void CommandThread::giveCommand(QByteArray commandIn)
{
    QString myCommand(commandIn);
    qDebug() << myCommand;
    system(commandIn.data());
}
