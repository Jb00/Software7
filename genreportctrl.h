#ifndef GENREPORTCTRL_H
#define GENREPORTCTRL_H

#include "genctrl.h"
#include "invalidwindow.h"
#include "Facility.h"
#include "Histogram.h"
#include "Graph.h"

class GenReportCtrl: public genCTRL
{
public:
    static GenReportCtrl* getInstance();
    void invalid();
    QList<Facility*> getFacilities();
    void center(QWidget &);
    void setupHistogram();
    void setupGraph();
    void mismatchCCCLTC();
    void occRateLTC();
    void occRateCCC();
    void occRateAC(QString ,QString,QString ,QString, QString );
    void sizeWL();
    void waitingTime();



private:
    GenReportCtrl();
    static GenReportCtrl* anInstance;
    InvalidWindow * invalidWin;

    QList<Facility*> facilitiesList;
    QList<QString> listId;
    QList<double> listData;
    Histogram* aHistogramReport;
    Graph* aGraphReport;



};

#endif // GENREPORTCTRL_H
