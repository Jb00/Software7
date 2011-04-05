#ifndef WAITINGLISTWINDOW_H
#define WAITINGLISTWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QDebug>

#include "waitingctrl.h"
#include "genui.h"
//#include "Patient.h" //WORKS FOR BART
//#include "facilitywinctrl.h"


namespace Ui {
    class WaitingListWindow;
}

class WaitingListWindow : public QMainWindow, public genUI
{
    Q_OBJECT

public:
    explicit WaitingListWindow(QWidget *parent = 0);
    ~WaitingListWindow();

    void keyPressEvent(QKeyEvent * event);


    void setScheme();

private:
    Ui::WaitingListWindow *ui;

  Patient *aPatient;

private slots:
    void cancelBtn_clicked();
    void addBtn_clicked();
    void searchBtn_clicked();
    void removeBtn_clicked();
};

#endif // WAITINGLISTWINDOW_H
