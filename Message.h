#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include <QString>
#include <QMainWindow>
#include <QDialog>
#include <qobject.h>
//#include "MessageController.h"



class Message
{
  //  Q_OBJECT
private:
        QUdpSocket *udpSocket;
        QUdpSocket *udpReceive;
public:
    Message();
    void treceive();
    void tsend(QString);
    int tmp;
};

#endif // MESSAGE_H

