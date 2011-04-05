#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>
#include <QDateTime>

//Patient
//Define a patient
//This is an entity object from Deliverable 1 && 2

class Patient
{

private :

//        QDate dateBirth;

        QString typeCareNeeded;
        QString facilityName;
        int bedNumber;

        int healthCardNum;
        QString fName;
        QString lName;
        QDateTime dateAdmitted;
        QDateTime dateWL;
        int reqCare;
        int occCare;



public:
    Patient(QString,QString,QString,QDateTime,QDateTime,int,int);
    Patient();
    ~Patient();

    void setNeeded(int);
    void setFacility(QString);
    void setBed(int);
    void setdateWL(QDateTime);
    void setOcc(int);
    int gethealthCard();
    QString getFName();
    QString getLName();
    QDateTime getAdmission();
    QDateTime getDateWL();
    int getNeeded(); //Needed Care
    int getOccCare();
    int getOcc();
    QString getFacility();

};
#endif // PATIENT_H


