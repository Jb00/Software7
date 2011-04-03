#ifndef ADDBEDCONTROLLER_H
#define ADDBEDCONTROLLER_H
#include <QString>
#include <QList>
#include <Bed.h>
#include <Facility.h>
#include <iostream>
#include <typeinfo>
class AddBedController
{
private :
        AddBedController();
        static AddBedController* anInstance;
        QList<Bed*> listBed;


public:
    static AddBedController* getInstance();
    void addtoBed(QString,QString,Facility*);
    void addBedXML(QString,QString,QString,QString,QString);
};

#endif // ADDBEDCONTROLLER_H
