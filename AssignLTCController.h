#ifndef ASSIGNLTCCONTROLLER_H
#define ASSIGNLTCCONTROLLER_H

#include <QList>
#include <QString>
#include "Patient.h"
#include "Facility.h"
#include <QtSql>
#include <QMessageBox>
#include <QSqlTableModel>
//#include "LongTermCare.h"


class AssignLTCController
{
private :
        static AssignLTCController* anInstance;
        AssignLTCController();
public:
    static AssignLTCController* getInstance();
    void assignBed(QList<Patient*>, Facility*);
};

#endif // ASSIGNLTCCONTROLLER_H
