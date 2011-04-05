#include "MessageController.h"
//#include "Message.h"
#include "xmlreader.h"


MessageController* MessageController::anInstance =NULL; // Global static pointer used to ensure a single instance of the class.


MessageController::MessageController()
    : QThread()
{
    connect(this,SIGNAL(mySignal()),this,SLOT(setStuff()));
   moveToThread(this);
   srand(time(NULL));

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
  //  theMessages.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\"><PatientList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"1\" occCare=\"1\"/></PatientList></Facility></Area></Add>");
  //  theMessages.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\" CCC=\"10\"/></Area></Add>");

    /*    theMessages.append("test2");
    theMessages.append("test3");
    theMessages.append("test4");
    theMessages.append("test5");
    theMessages.append("test10");*/


    Message * message = new Message;


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\"><PatientList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"1\" occCare=\"1\"/></PatientList></Facility></Area></Add>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\"><PatientList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"4444333222\" dateAdmitted=\"1920-03-02T11:15:32\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"1\" occCare=\"1\"/></PatientList></Facility></Area></Delete>");


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\" CCC=\"10\"/></Area></Add>");

 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><Facility ID=\"7\" CCC=\"15\"/></Area></Delete>");

 //     receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Add remote=\"true\"><Area ID=\"5\"><WaitingList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"545687\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/></WaitingList></Area></Add>");
 //    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Delete remote=\"true\"><Area ID=\"5\"><WaitingList><Patient firstName=\"Jon\" lastName=\"Doe\" healthCardNumber=\"545687\" dateAdded=\"1920-03-02T11:15:32\" reqCare=\"3\" occCare=\"1\"/></WaitingList></Area></Delete>");


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"13\"/><ACRecord occupied=\"500\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");
 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Response ID=\"23205\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord dateTime=\"2002-05-30T09:00:00\"><Facility ID=\"7\"/><ACRecord occupied=\"0\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Response>");


 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"25\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Response ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord dateTime=\"2002-05-30T09:00:00\"><Facility ID=\"7\"/><ACRecord occupied=\"120\"/></FacilityRecord></Report></Response>");
//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Response ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord dateTime=\"2002-05-30T09:00:00\"><Facility ID=\"12\"/><ACRecord occupied=\"80\"/></FacilityRecord></Report></Response>");

       while(1)
        {
   //     message->treceive();
        if(!theMessages.isEmpty())
        {
            message->tsend(theMessages.at(0));
            theMessages.removeAt(0);
        }
        message->treceive();

        //Deal with the head of the received messages //might do it for all messages so it is faster???
        if(!receivedMessage.isEmpty())
        {
            qDebug() << receivedMessage.at(0);
            if(XMLReader::getInstance()->readRequest(receivedMessage.at(0)) == "-2")
            {
                reportList.append(receivedMessage.at(0)); //Add it to the report list

               qDebug()<<"SIZE LIST"<< reportList.size();
            }
            else
            {
                if (XMLReader::getInstance()->readRequest(receivedMessage.at(0)) != "-1")
                {
                    theMessages.append(XMLReader::getInstance()->readRequest(receivedMessage.at(0)));
                }
            }

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


//Set things for report.
QList<QString> MessageController::setGetData(QList<QString> aList,QString AC,QString CCC,QString LTC,QDateTime to,QDateTime from)
    {
    QList<QString> returnList;
    QString anId;
//    int id = rand() % 5000;
    int id = 2705;
    anId.setNum(id);
    qDebug() << id;
    QString toString =to.toString("yyyy-MM-dThh:mm:ss");
    QString fromString =from.toString("yyyy-MM-dThh:mm:ss");
    int size = aList.size();
    int k=0; //for sending
    int i=0; //For searching through the list of received
    QString compareString;
    //Facility A demands

        toSend(XMLReader::getInstance()->requestAmountOfBeds(aList,AC,CCC,LTC,anId,toString,fromString));

    //Example that we received asking us our bed.

    //Facility B receive this
        //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"500\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"25\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

    QTime t;
    t.start();
    t.restart();
    qDebug() << t.elapsed();
    //For 10 seconds
    //Wait to see if B will answers
   while((t.elapsed() < 100) && (returnList.size() < 500))
   {

        //Check for each element in the received list if they have the id requested
        while(i <reportList.size())
        {
            QString requestID;
            compareString = reportList.at(i);
            QDomDocument doc("xmldocument");
            if (doc.setContent(compareString)) {
                //Get the root element
                QDomElement root = doc.documentElement();

               requestID = root.attribute("ID");
            }

            //If they are equal then add to return list and remove from received list.
            if (requestID == anId)
            {
                returnList.append(reportList.at(i));
                reportList.removeAt(i);
            }
        }
        //Retake time
    }

    qDebug() << t.elapsed();
    qDebug() <<"Size "<<returnList.size();

    if(returnList.empty())
        returnList.append("Empty");
    return returnList;
}

QList<QString> MessageController::setgetMismatchOccLTC(QList<QString> aList, QDateTime from, QDateTime to,QString type,QString occupied)
{
    QList<QString> returnList;
    QString anId;
//    int id = rand() % 5000;
    int id = 2705; //TO CHANGE AFTER TEST
    anId.setNum(id);
    QString toString =to.toString("yyyy-MM-dThh:mm:ss");
    QString fromString =from.toString("yyyy-MM-dThh:mm:ss");
    int size = aList.size();
    int k=0; //for sending
    int i=0; //For searching through the list of received
    QString compareString;
    //Facility A demands
  //  QString XMLReader::requestMismatches(QList<QString> facilityIDs, QString typeOfBed, QString occupiedByBed, QString requestID, QString startDate, QString endDate);

    toSend(XMLReader::getInstance()->requestMismatches(aList,type,occupied,anId,fromString,toString));


    //Example that we received asking us our bed.

    //Facility B receive this

 //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2735\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><CCCRecord occupiedByLTC=\"0\"/></FacilityRecord></Report></Request>");


    QTime t;
    t.start();
    //For 10 seconds
    //Wait to see if B will answers
    while(t.elapsed() < 5000 && returnList.size() < 500)
    {
        i=0;
        //Check for each element in the received list if they have the id requested
        while(i <reportList.size())
        {
            QString requestID;
            compareString = reportList.at(i);
            QDomDocument doc("xmldocument");
            if (doc.setContent(compareString)) {
                //Get the root element
                QDomElement root = doc.documentElement();

               requestID = root.attribute("ID");
            }

            //If they are equal then add to return list and remove from received list.
            if (requestID == anId)
            {
                qDebug() <<"NOT EATEN";
                returnList.append(reportList.at(i));
                reportList.removeAt(i);
                i--;
            }
            i++;
        }
        //Retake time
    }

    qDebug() <<"Size "<<returnList.size();

    if(returnList.empty())
        returnList.append("Empty");
    return returnList;
}

QList<QString> MessageController::setgetWLSize(QList<QString> aList,QDateTime to,QDateTime from)
{
    QList<QString> returnList;
    QString anId;
//    int id = rand() % 5000;
    int id = 2705;
    anId.setNum(id);
    qDebug() << id;
    QString toString = to.toString("yyyy-MM-dThh:mm:ss");
    QString fromString =from.toString("yyyy-MM-dThh:mm:ss");
    int size = aList.size();
    int k=0; //for sending
    int i=0; //For searching through the list of received
    QString compareString;
    //Facility A demands

        toSend(XMLReader::getInstance()->requestWaitingListSize(anId,toString,fromString));

    //Example that we received asking us our bed.

    //Facility B receive this
        //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"500\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"25\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

    QTime t;
    t.start();
    t.restart();
    qDebug() << t.elapsed();
    //For 10 seconds
    //Wait to see if B will answers
   while((t.elapsed() < 100) && (returnList.size() < 500))
   {

        //Check for each element in the received list if they have the id requested
        while(i <reportList.size())
        {
            QString requestID;
            compareString = reportList.at(i);
            QDomDocument doc("xmldocument");
            if (doc.setContent(compareString)) {
                //Get the root element
                QDomElement root = doc.documentElement();

               requestID = root.attribute("ID");
            }

            //If they are equal then add to return list and remove from received list.
            if (requestID == anId)
            {
                returnList.append(reportList.at(i));
                reportList.removeAt(i);
            }
        }
        //Retake time
    }

    qDebug() << t.elapsed();
    qDebug() <<"Size "<<returnList.size();

    if(returnList.empty())
        returnList.append("Empty");
    return returnList;
}


QList<QString> MessageController::setgetWLTime(QList<QString> aList,QDateTime to,QDateTime from)
{
    QList<QString> returnList;
    QString anId;
//    int id = rand() % 5000;
    int id = 2705;
    anId.setNum(id);
    qDebug() << id;
    QString toString = to.toString("yyyy-MM-dThh:mm:ss");
    QString fromString =from.toString("yyyy-MM-dThh:mm:ss");
    int size = aList.size();
    int k=0; //for sending
    int i=0; //For searching through the list of received
    QString compareString;
    //Facility A demands

    //WILL BE TO CHANGED W/ ID HERE FOR LOOP

        toSend(XMLReader::getInstance()->requestWaitTimes(anId,toString,fromString));

    //Example that we received asking us our bed.

    //Facility B receive this
        //   receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"500\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

//    receivedMessage.append("<?xml version=\"1.0\" encoding=\"utf-8\"?><Request ID=\"2705\"><Report startDate=\"2002-05-30T09:00:00\" endDate=\"1994-05-30T09:00:00\"><FacilityRecord><Facility ID=\"7\"/><ACRecord occupied=\"25\"/><CCCRecord occupied=\"0\"/><LTCRecord occupied=\"0\"/></FacilityRecord></Report></Request>");

    QTime t;
    t.start();
    t.restart();
    qDebug() << t.elapsed();
    //For 10 seconds
    //Wait to see if B will answers
   while((t.elapsed() < 100) && (returnList.size() < 500))
   {

        //Check for each element in the received list if they have the id requested
        while(i <reportList.size())
        {
            QString requestID;
            compareString = reportList.at(i);
            QDomDocument doc("xmldocument");
            if (doc.setContent(compareString)) {
                //Get the root element
                QDomElement root = doc.documentElement();

               requestID = root.attribute("ID");
            }

            //If they are equal then add to return list and remove from received list.
            if (requestID == anId)
            {
                returnList.append(reportList.at(i));
                reportList.removeAt(i);
            }
        }
        //Retake time
    }

    qDebug() << t.elapsed();
    qDebug() <<"Size "<<returnList.size();

    if(returnList.empty())
        returnList.append("Empty");
    return returnList;
}



void MessageController::xmlToAction(QString aXML)
{
    //XMLReader *xr = new XMLReader();

    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //every request will go into readRequest and unless the request is for us to add/delete         //
    //bed or add/delete people from a a waiting list                                                //
    //then the response that needs to be sent back will go in a QString , then you just             //
    //send them back that QString                                                                   //
    QString somethingThatTheyHaveAskedUsToDo =  XMLReader::getInstance()->readRequest(aXML);        //
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////
    qDebug() << "the Response " << somethingThatTheyHaveAskedUsToDo;

}
