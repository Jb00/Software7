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
    ~Patient();

    void setNeeded(int);
    void setFacility(QString);
    void setBed(int);
    void setdateWL(QDateTime);
    int gethealthCard();
    QString getFName();
    QString getLName();
    QDateTime getAdmission();
    QDateTime getDateWL();
    int getNeeded(); //Needed Care

};
#endif // PATIENT_H


