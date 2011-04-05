#ifndef WAITINGCTRL_H
#define WAITINGCTRL_H

#include "Patient.h"
#include "genctrl.h"
#include "invalidwindow.h"


class WaitingCtrl: public genCTRL
{
public:

    Patient* searchForPatient(int);
    void removePatient(Patient*);
    static WaitingCtrl* getInstance();

    void invalid(QString);

private:
    static WaitingCtrl* anInstance;
    WaitingCtrl();

    Patient* aPatient;
    InvalidWindow* invalidWin;

};

#endif // WAITINGCTRL_H
