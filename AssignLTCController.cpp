#include "AssignLTCController.h"

AssignLTCController* AssignLTCController::anInstance =NULL;

AssignLTCController::AssignLTCController()
{
}

AssignLTCController* AssignLTCController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AssignLTCController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AssignLTCController::assignBed(QList<Patient *> aList, Facility * aLTC) //put LTC
{
    for (int i =0; i< aList.size(); i++)
    {
        if ((aLTC->removePatientWL(aList.at(i)->gethealthCard()))&& (aLTC->NUsedBedLTC())) //If remove of the patient in the WL worked and there is an empty bed in the facility
        {
           aLTC->addPatientLTC(aList.at(i)); //Add to the facility
        }
    }
}
