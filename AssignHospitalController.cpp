#include "AssignHospitalController.h"
#include "mapwinctrl.h"

/*
#include <QString>
#include <QList>
#include "Patient.h"
#include "Facility.h"
*/

AssignHospitalController* AssignHospitalController::anInstance =NULL;

AssignHospitalController::AssignHospitalController()
{
}

AssignHospitalController::~AssignHospitalController()
{
}

AssignHospitalController* AssignHospitalController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AssignHospitalController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AssignHospitalController::addtoBed(Patient * aPatient, Facility * aFacility,QString aType)
//void AssignHospitalController::addtoBed(QString aHealthCardNum,QString aFName,QString aLName,QString aDateAdmitted,QString aDateWL,QString aReqCare,QString anOccCare,QString aFacilityId)
{

    if(aType == "Complex")
    {
            if (aFacility->NUsedBedComplex())
            {
                std::cout <<"COMPLEX";
                aFacility->addPatientComplex(aPatient);
            }
    }
    else
        if(aType == "Acute")
        {
             if (aFacility->NUsedBedAcute())
             {
                 std::cout <<"SUPER INSIDE"<<std::endl;
                 aFacility->addPatientAcute(aPatient);
             }
        }
        else
            std::cout<<"ERROR";                                         //Test only , should not happens.
}

//We can use this always ? probably ? Will have to wait for BART UI
void AssignHospitalController::setXmlNewPatient(QString aHealthCardNum,QString aFName,QString aLName,QString aDateAdmitted,QString aDateWL,QString aReqCare,QString anOccCare,QString aFacilityId)
{
    QDateTime aDate = QDateTime::fromString("2003-05-30T09:00:00","yyyy-MM-dThh:mm:ss");

    int x;

    Facility * aFacility;


    QDateTime dateAdmitted = QDateTime::fromString(aDateAdmitted,"yyyy-MM-dThh:mm:ss");
    QDateTime datewl = QDateTime::fromString(aDateWL,"yyyy-MM-dThh:mm:ss");
    int req = aReqCare.toInt();
    int occ = anOccCare.toInt();
    Patient * aPatient = new Patient(aHealthCardNum,aFName,aLName,dateAdmitted,datewl, req,occ);
    //Now we have the patient, to access the facility, we have to find it. WE can do that by requesting list and looping through it.
    aFacility =  MapWinCtrl::getInstance()->getFacilityFromid(aFacilityId);






    //Add to bed for the correct type , if and only if there is room.
        if (occ == 0)
               {
                   if (aFacility->NUsedBedAcute())
                   {
                       aFacility->addPatientAcute(aPatient);
                   }
               }
        else{
                   if (occ == 1)
                   {
                       if (aFacility->NUsedBedComplex())
                       {
                           aFacility->addPatientComplex(aPatient);
                       }
                   }
               }

    //Check if we are adding to our facility. If we do add to the DB.

    if (aFacilityId.toInt() == MapWinCtrl::getInstance()->getId())
    {
        QSqlQuery query;
        QString queryText;

        //MISS AREA AND FACILITY ID UNSURE YET


        //the main insert script
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        queryText = "INSERT INTO patient (dateAdmitted,datePlacedOnWaitingList,firstName,healthCardNum, lastName ,occCare,reqCare)"
                    " VALUES (:dateAdmitted,:datePlacedOnWaitingList,:firstName,:healthCardNum, :lastName ,:occCare,:reqCare)";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        query.prepare(queryText);

        //binding the variables from the form to the query
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        query.bindValue(":dateAdmitted", aDateAdmitted);
        query.bindValue(":datePlacedOnWaitingList", aDateWL);
        query.bindValue(":firstName", aFName);
        query.bindValue(":healthCardNum", aHealthCardNum);
        query.bindValue(":lastName", aLName);
        query.bindValue(":occCare", anOccCare);
        query.bindValue(":reqCare", aReqCare);

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        query.exec(); //executing the query
    }


}

void AssignHospitalController::setXmlRemovePatient(QString aHealthCardNum,QString aFName,QString aLName,QString aDateAdmitted,QString aDateWL,QString aReqCare,QString anOccCare,QString aFacilityId)
{
    Facility * aFacility;
    aFacility =  MapWinCtrl::getInstance()->getFacilityFromid(aFacilityId);
    int req = aReqCare.toInt();
    int occ = anOccCare.toInt();
    double healthCardNum2 = aHealthCardNum.toDouble();

    if (occ == 0)
        aFacility->removePatientAcute(healthCardNum2);
    else
        if (occ == 1)
        {
            aFacility->removePatientComplex(healthCardNum2);
        }

    if (aFacilityId.toInt() == MapWinCtrl::getInstance()->getId())
    {
        QSqlQuery query;
        QString queryText;

        //the main insert script
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        query.exec("DELETE FROM patient WHERE healthCardNum =" + aHealthCardNum);
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    }
      //  else
      //      if (req == 2)
      //          aFacility->removePatientLTC(healthCardNum);
}



