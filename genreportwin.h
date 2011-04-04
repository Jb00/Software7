#ifndef GENREPORTWIN_H
#define GENREPORTWIN_H

#include <QMainWindow>
#include <QList>
#include <QListView>

#include "genreportctrl.h"
#include "Facility.h"

namespace Ui {
    class GenReportWin;
}

class GenReportWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit GenReportWin(QWidget *parent = 0);
    ~GenReportWin();
    void setScheme();
    void setUpList();

private:
    Ui::GenReportWin *ui;

    QList<Facility*> *facilities;

private slots:

    void cancelBtn_clicked();
    void genBtn_clicked();
    void bedInfoRadio_selected();
    void bedInfoCheck_selected();
    void patientInfoCheck_selected();
    void waitingCheck_selected();
    void facilityList_selected();
};

#endif // GENREPORTWIN_H
