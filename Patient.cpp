
#include "Patient.h"

Patient::Patient(QString aHealthCardNum,QString aFName,QString aLName,QDateTime aDateAdmitted,QDateTime aDateWL,int aReqCare,int anOccCare)
{
    healthCardNum =aHealthCardNum.toInt();
    fName = aFName;
    lName = aLName;
    dateAdmitted = aDateAdmitted;
    dateWL = aDateWL;
    reqCare = aReqCare;
    occCare = anOccCare;
}



void Patient::setNeeded(int aType)
{
    reqCare = aType;
}

void Patient::setFacility(QString aFacility)
{
    facilityName =aFacility;
}

void Patient::setBed(int aBed)
{
    bedNumber =aBed;
}

void Patient::setdateWL(QDateTime aDate)
{
    dateWL =aDate;
}

int Patient::gethealthCard()
{
    return healthCardNum;
}

QString Patient::getFName()
{
    return fName;
}

QString Patient::getLName()
{
    return lName;
}

QDateTime Patient::getDateWL()
{
    return dateWL;
}

QDateTime Patient::getAdmission()
{
    return dateAdmitted;
}

int Patient::getNeeded()
{
    return reqCare;
}

/*QString Patient::getFacility()
{
    return facilityName;
}

int Patient::getBed()
{
    return bedNumber;
}
*/






