#include "AddWLController.h"
#include "mapwinctrl.h"

AddWLController* AddWLController::anInstance =NULL; // Global static pointer used to ensure a single instance of the class.

AddWLController::AddWLController()
{
}


AddWLController* AddWLController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddWLController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AddWLController::addWaitingList(Patient * aPatient,Facility * aLTC)
{
    QDateTime today;

    today.currentDateTime();
    qDebug() << today;
    QDateTime anowDate(today);
    aPatient->setdateWL(anowDate);
    aLTC->addWaitingList(aPatient);
}

void AddWLController::addWaitingListXML(QString aHealthCardNum,QString aFName,QString aLName,QString aDateAdmitted,QString aDateWL,QString aReqCare,QString anOccCare,QString area)
{
    QDateTime today;

    Facility * aFacility ;
    int idFacility;
    QString idFacilityString;

    today = today.currentDateTime();
    QDateTime anowDate(today);
    QDateTime dateWL = QDateTime::fromString(aDateWL,"yyyy-MM-dThh:mm:ss");
    QDateTime dateadmitted =QDateTime::fromString("1.30.1","M.d.s");//Default one
    Patient * aPatient = new Patient(aHealthCardNum,aFName,aLName,dateadmitted,dateWL, aReqCare.toInt(),anOccCare.toInt());

  //  idFacility = MapWinCtrl::getInstance()->getWlArray(area.toInt()); //Get facility id of the facility that has the WL for that area
    //WILL WORK WHEN WE HAVE MORE DATA AND PROTOCOL

    idFacility=7;
    idFacilityString.setNum(idFacility);
    aFacility = MapWinCtrl::getInstance()->getFacilityFromid(idFacilityString);
    aFacility->addWaitingList(aPatient); //Add patient to the WL

    qDebug()<< "FUCK YOU WORK BITCH :"<<aFacility->getSizeWL();



    if (idFacilityString.toInt() == MapWinCtrl::getInstance()->getId())
    {
        QSqlQuery query;
        QString queryText;

        //the main insert script
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        queryText = "INSERT INTO waitinglist (areaID,patientID,wlRecordID,dte_added,dte_admitted)"
                    "VALUES (:areaID,:patientID,:wlRecordID,:dte_added ,:dte_admitted)";
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        query.prepare(queryText);

        //binding the variables from the form to the query
        int anArea,patientid,wlrecordid;
        anArea = area.toInt();
        patientid = aHealthCardNum.toInt();
        wlrecordid = aHealthCardNum.toInt();

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        query.bindValue(":areaID", anArea);
        query.bindValue(":patientID", patientid);
        query.bindValue(":wlRecordID", wlrecordid); //TO CHANGE TO REAL STUFF
        query.bindValue(":dte_added", aDateWL);
        query.bindValue(":dte_admitted", "2");
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        query.exec(); //executing the query
    }
}

int AddWLController::getSize(Facility * aLTC)
{
    return aLTC->getSizeWL();
}

void AddWLController::deleteWaitingListXML(QString idPatient, QString area)
{
    //First find facility
    //Second delete user from that facility
    //Check if it is our facility that hold db, if true then delete it from db

    Facility * aFacility ;
    int idFacility;
    QString idFacilityString;


    //  idFacility = MapWinCtrl::getInstance()->getWlArray(area.toInt()); //Get facility id of the facility that has the WL for that area
      //WILL WORK WHEN WE HAVE MORE DATA AND PROTOCOL

      idFacility=7;
      idFacilityString.setNum(idFacility);
      aFacility = MapWinCtrl::getInstance()->getFacilityFromid(idFacilityString);

      if(aFacility->removePatientWL(idPatient.toInt())) //If remove didnt fail
      {
          qDebug() << "test INSIDE";

          if (idFacilityString.toInt() == MapWinCtrl::getInstance()->getId())
          {
              QSqlQuery query;
              QString queryText;
              int idInt = idPatient.toInt();
              qDebug() <<idInt;

              //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
             query.exec("DELETE FROM waitingList WHERE patientID =" + idPatient);
              //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          }
      }



}


