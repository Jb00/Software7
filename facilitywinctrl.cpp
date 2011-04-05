#include "facilitywinctrl.h"

FacilityWinCtrl* FacilityWinCtrl::anInstance = NULL;

FacilityWinCtrl::FacilityWinCtrl()
{
}

FacilityWinCtrl* FacilityWinCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new FacilityWinCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void FacilityWinCtrl::goToWaiting(){

    waitingWin = new WaitingListWindow();
    waitingWin->show();

    genCTRL::center(*waitingWin);
}

void FacilityWinCtrl::setType(QString type){aType = type;}
QString FacilityWinCtrl::getType(){return aType;}

void FacilityWinCtrl::goToNewPatient(Facility *aFacility){

    newPatientWin = new NewPatientWindow();
    newPatientWin->show();
    newPatientWin->currentFacility(aFacility);

    genCTRL::center(*newPatientWin);
}











