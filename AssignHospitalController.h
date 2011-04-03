#ifndef ASSIGNHOSPITALCONTROLLER_H
#define ASSIGNHOSPITALCONTROLLER_H
#include <QString>
#include <QList>
#include "Patient.h"
#include "Facility.h"

//#include "mapwinctrl.h"

class AssignHospitalController
{

private :
        AssignHospitalController();
        static AssignHospitalController* anInstance;
     //  Facility aFacility2;
        //Facility * aFacility;

public:
        static AssignHospitalController* getInstance();
        void addtoBed(Patient * , Facility * ,QString );
        void setXmlNewPatient(QString,QString,QString,QString,QString,QString,QString,QString);
        void setXmlRemovePatient(QString,QString,QString,QString,QString,QString,QString,QString);
        ~AssignHospitalController();

};

#endif // ASSIGNHOSPITALCONTROLLER_H
