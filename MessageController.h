#ifndef MESSAGECONTROLLER_H
#define MESSAGECONTROLLER_H

#include <QString>
#include <QList>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QDate>
#include <qdatetime.h>

#include <QtXml/QDomDocument>
#include "Message.h"
#include "xmlreader.h"
#include <QList>

#include "mapwinctrl.h"
#include <stdlib.h> //For random
#include <time.h>


class MessageController : public QThread
{
    Q_OBJECT
private :
 //       Message * aMessage;
        MessageController();
        static MessageController* anInstance; //The instance of the Singleton

        QList<QString> theMessages;
        QList<QString> receivedMessage;
        QList<QString> reportList;
        XMLReader *xr;
        void xmlToAction(QString );

public:
        static MessageController* getInstance();
        void toSend(QString);
        ~MessageController();
        void run();
        void received(QString);
        QList<QString> setGetData(QList<QString>,QString,QString,QString,QDateTime,QDateTime);
        QList<QString> setgetMismatchOccLTC(QList<QString>,QDateTime,QDateTime,QString,QString);
        QList<QString> setgetWLSize(QList<QString>,QDateTime,QDateTime);
        QList<QString> setgetWLTime(QList<QString>,QDateTime,QDateTime);



private slots:
   // void sendMessage();
   void setStuff();

signals :
        void mySignal();
};

#endif // MESSAGECONTROLLER_H
