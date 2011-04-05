#ifndef MAPWINCTRL_H
#define MAPWINCTRL_H

#include<QList>
#include <QDialog>
#include <QtSql>
#include <QMessageBox>
#include <QSqlTableModel>
#include "Facility.h"
#include "Patient.h"
#include "facilitywindow.h"
#include "adduserctrl.h"
#include "adduserwindow.h"
#include "addfacility.h"
#include "ReportController.h"
#include "genreportwin.h"

/*

#include "genctrl.h"
#include "adduserctrl.h"
#include "MessageController.h"



#include "invalidwindow.h"
*/

#include <QDateTime>
class MapWinCtrl: public genCTRL
{
public:


    ~MapWinCtrl();

    void goToAddUser();
    void goToAddFac(const QPoint &, const int &, const QColor &);
    void setupPatients();
    void setupFacility();
    void gotoFacility();
    void setupUser();
    int getId();
    static MapWinCtrl* getInstance();
    Facility* getFacilityFromid(QString);
    void setWlArray(QString,QString);
    int getWlArray(int);
    void setReport();
    void goToGenerate();


    void invalid();
    QList<Facility*> listOfFacility;
    QList<Patient*> listOfPatient;
    void addToFacilityList(int facilityID,QString facilityName,int x,int y,int aAC,int aCCC,int aLTC);


private:

    static MapWinCtrl* anInstance;
    MapWinCtrl();
    AddUserWindow* addUserWin;
    AddFacility* addFac;
    FacilityWindow* aFacilityView;
    InvalidWindow* invalidWin;
    GenReportWin* reportWin;
    int wlArray[5];

    //FAKE DATA TEST


 //   QList<Patient*> listOfPatient;
 //   QList<Facility*>listOfFacility;
    QList<User*> listOfUser;


    //Test Patient for Add patient to LTC
    Patient * aPatient11;
    Patient * aPatient12;
    Patient * aPatient13;
    Patient * aPatient14;
    Patient * aPatient15;
    Patient * aPatient16;
    Patient * aPatient17;
    QList<Patient*> aPatientList;

    Facility * aFacility2;
    Facility * aFacility3;
    Facility * aFacility4;
};

#endif // MAPWINCTRL_H

