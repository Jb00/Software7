#ifndef FACILITYWINCTRL_H
#define FACILITYWINCTRL_H

#include "genctrl.h"
#include "waitinglistwindow.h"
#include "newpatientwindow.h"

class FacilityWinCtrl: public genCTRL
{
public:

    static FacilityWinCtrl* getInstance();
    void goToWaiting();
    void setType(QString);

    QString getType();
    void goToNewPatient(Facility*);

private:
    FacilityWinCtrl();
    static FacilityWinCtrl* anInstance;

    WaitingListWindow *waitingWin;
    NewPatientWindow *newPatientWin;
    QString aType;


};

#endif // FACILITYWINCTRL_H
