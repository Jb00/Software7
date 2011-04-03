#include "MessageController.h"
//#include "Message.h"
#include "xmlreader.h"


MessageController* MessageController::anInstance =NULL; // Global static pointer used to ensure a single instance of the class.


MessageController::MessageController()
    : QThread()
{
    connect(this,SIGNAL(mySignal()),this,SLOT(setStuff()));
   moveToThread(this);

}

MessageController::~MessageController()
{

}

void MessageController::run()
{
   // QTimer::singleShot(0,this,SLOT(setStuff()));
   emit(mySignal());
}

MessageController* MessageController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new MessageController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void MessageController::setStuff()
{
    theMessages.append("test1");
    theMessages.append("test2");
    theMessages.append("test3");
    theMessages.append("test4");
    theMessages.append("test5");
    theMessages.append("test10");


    Message * message = new Message;


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\"><PatientList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"1\" occCare=\"1\"/></PatientList></Facility></Area></Add>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\"><PatientList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"1\" occCare=\"1\"/></PatientList></Facility></Area></Delete>");


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\" CCC=\"10\"/></Area></Add>");

 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\" CCC=\"15\"/></Area></Delete>");

      receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><WaitingList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"545687\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/></WaitingList></Area></Add>");
      receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><WaitingList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"545687\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/></WaitingList></Area></Delete>");


       while(1)
        {
   //     message->treceive();
        if(!theMessages.isEmpty())
        {
  //          message->tsend(theMessages.at(0));
            theMessages.removeAt(0);
        }
    //    message->treceive();

        //Deal with the head of the received messages //might do it for all messages so it is faster???
        if(!receivedMessage.isEmpty())
        {
            qDebug() << receivedMessage.at(0);
            xmlToAction(receivedMessage.at(0));
            receivedMessage.removeAt(0);
        }
    }
}

void MessageController::toSend(QString aMessage)
{
    theMessages.append(aMessage);
}

void MessageController::received(QString aReceived)
{
    receivedMessage.append(aReceived);
    qDebug() << receivedMessage.size();
}

QList<QString> MessageController::setGetData(QList<QString> aList,QString aType,QDate to,QDate from)
    {
    QList<QString> returnList;
    QString anId;
    int id = random() * 5000;
    anId.setNum(id);
    int size = aList.size();
    int k=0; //for sending
    int i=0; //For searching through the list of received
    QString compareString;
    while (k < size)
    {
        toSend("");
        k++;
    }

    qint64 value = QDateTime::currentMSecsSinceEpoch() + 10000; //Time to stop at (10 seconds after now)
    qint64 now = QDateTime::currentMSecsSinceEpoch(); //now time

    //For 10 seconds
    while(value >now )
    {
        //Check for each element in the received list if they have the id requested
        while(i <receivedMessage.size())
        {
            QString requestID;
            compareString = receivedMessage.at(i);
            QDomDocument doc("xmldocument");
            if (doc.setContent(compareString)) {
                //Get the root element
                QDomElement root = doc.documentElement();

               requestID = root.attribute("ID");
            }

            //If they are equal then add to return list and remove from received list.
            if (requestID.compare(anId))
            {
                returnList.append(receivedMessage.at(i));
                receivedMessage.removeAt(i);
            }
        }
        //Retake time
        now = QDateTime::currentMSecsSinceEpoch(); //now time
    }

    if(returnList.empty())
        returnList.append("Empty");
    return returnList;
}

void MessageController::xmlToAction(QString aXML)
{
    XMLReader *xr = new XMLReader();

    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //every request will go into readRequest and unless the request is for us to add/delete         //
    //bed or add/delete people from a a waiting list                                                //
    //then the response that needs to be sent back will go in a QString , then you just             //
    //send them back that QString                                                                   //
    QString somethingThatTheyHaveAskedUsToDo =  xr->readRequest(aXML);                              //
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    qDebug() << "the Response " << somethingThatTheyHaveAskedUsToDo;

}
