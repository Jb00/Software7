#ifndef ADDFACCTRL_H
#define ADDFACCTRL_H

#include <QDialog>

#include <QList>
#include <QString>
#include <QtSql>
#include <QMessageBox>
#include <QSqlTableModel>
#include <QPoint>

//#include "addfacility.h"
#include "Facility.h"
#include "genctrl.h"
#include "invalidwindow.h"


class AddFacCtrl: public genCTRL
{
private :
        AddFacCtrl();
        static AddFacCtrl* anInstance;
        InvalidWindow * invalidWin;

        int id;
        QString facilityName;
        int x;
        int y;
        int AC;
        int CCC;
        int LTC;
        int area; //MAYBE
      //  QList<Facility *> *facilityList;

public:

    QList<Facility *> *facilityList;
    static AddFacCtrl* getInstance();

    void invalid();
    void addFacilityCoord(int, int);

    void addToDb();
    void setId(int);
    void setX(int);
    void setY(int);
    void setAC(int);
    void setCCC(int);
    void setLTC(int);
    void setName(QString);
    void setArea(int);
    void setList(QList<Facility *>*);

    int getArea();
    int getAC();
    int getCCC();
    int getLTC();
};

#endif // ADDFACCTRL_H


