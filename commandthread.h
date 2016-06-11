#ifndef COMMANDTHREAD_H
#define COMMANDTHREAD_H
#include <QByteArray>
#include <QThread>
#include <QDebug>

class CommandThread : public QThread
{
public:
    void run();
    void giveCommand(QByteArray commandIn);
signals:

public slots:
};

#endif // COMMANDTHREAD_H
