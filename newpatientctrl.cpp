#include "newpatientctrl.h"
#include "facilitywinctrl.h"

NewPatientCtrl* NewPatientCtrl::anInstance = NULL;

NewPatientCtrl::NewPatientCtrl(){}

void NewPatientCtrl::invalid(QString message){

    invalidWin = new InvalidWindow();

    invalidWin->setLabelText(message);
    invalidWin->show();

    genCTRL::center(*invalidWin);
}


NewPatientCtrl* NewPatientCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new NewPatientCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void NewPatientCtrl::addPatient(QString card, QString fName, QString lName, QDateTime admitted, QDateTime waiting, int reqCare, int occCare, Facility *current){

    aPatient = new Patient(card, fName, lName, admitted, waiting, reqCare, occCare);
    QString req;
    QString occ;
    QString id;

    req.setNum(reqCare);
    occ.setNum(occCare);
    id.setNum(current->getId());

    if(reqCare == 0){
        aPatient->setOcc(0);
        AssignHospitalController::getInstance()->addtoBed(aPatient,current,"Acute");
        AssignHospitalController::getInstance()->setXmlNewPatient(card, fName, lName, admitted.toString(), waiting.toString(), req,
                                                                  occ, id);

    }
    else if(reqCare == 1){
        aPatient->setOcc(1);
        AssignHospitalController::getInstance()->addtoBed(aPatient, current, "Complex");
        AssignHospitalController::getInstance()->setXmlNewPatient(card, fName, lName, admitted.toString(), waiting.toString(), req,
                                                                  occ, id);
    }
}

int Patient::getOcc(){return occCare;}
void Patient::setOcc(int occType){occCare = occType;}
