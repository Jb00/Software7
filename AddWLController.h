#ifndef ADDWLCONTROLLER_H
#define ADDWLCONTROLLER_H
#include <QList>
#include <QDate>
#include "Patient.h"
#include "Facility.h"

#include <iostream>
#include <QString>
class AddWLController
{
private :

        static AddWLController* anInstance; //The instance of the Singleton
        AddWLController(); //So it cannot be call from the outside
public:
    static AddWLController* getInstance();
    void addWaitingList(Patient*,Facility*);
    int getSize(Facility* ); //Size of WL
    void addWaitingListXML(QString,QString,QString,QString,QString,QString,QString,QString area);
    void deleteWaitingListXML(QString,QString);
    //DESCTRUCTOR
    ~AddWLController();
};

#endif // ADDWLCONTROLLER_H

