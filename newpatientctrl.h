#ifndef NEWPATIENTCTRL_H
#define NEWPATIENTCTRL_H

#include "genctrl.h"
#include "invalidwindow.h"
#include "Facility.h"
#include "Patient.h"
#include "AssignHospitalController.h"

#include <QDateTime>

class NewPatientCtrl: public genCTRL
{
public:
    static NewPatientCtrl* getInstance();
    void invalid(QString);

    void addPatient(QString, QString, QString, QDateTime, QDateTime, int, int, Facility*);

private:
    NewPatientCtrl();
    static NewPatientCtrl* anInstance;

    InvalidWindow* invalidWin;
    Patient* aPatient;

};

#endif // NEWPATIENTCTRL_H
