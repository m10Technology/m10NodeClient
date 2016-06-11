#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QDebug>
#include <QThread>
#include <QTcpSocket>
#include <QList>
#include "commandthread.h"

class Client : public QThread
{
    Q_OBJECT
public:
    Client();
    void run();
    void connectToServer(QString ipAddress);
signals:

private:
    char* getIP(void);
    QTcpSocket *socket;
    QList<QByteArray> commands;
    CommandThread *commandExecutor[1024];
    int commandCounter = 0;
public slots:
    void readyRead();
    void disconnected();
};

#endif // CLIENT_H
