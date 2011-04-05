#ifndef NEWPATIENTWINDOW_H
#define NEWPATIENTWINDOW_H

#include <QMainWindow>
#include <QDateTime>

#include "genui.h"
#include "newpatientctrl.h"
#include "Facility.h"

namespace Ui {
    class NewPatientWindow;
}

class NewPatientWindow : public QMainWindow, public genUI
{
    Q_OBJECT

public:
    explicit NewPatientWindow(QWidget *parent = 0);
    ~NewPatientWindow();

    void setScheme();
    void currentFacility(Facility *);

private:
    Ui::NewPatientWindow *ui;

    Facility *aFacility;

private slots:

    void okBtn_clicked();
    void cancelBtn_clicked();
};

#endif // NEWPATIENTWINDOW_H
