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
    void mismatchCCCLTC(QString,QString ,QString);
    void mismatchACLTC(QString,QString ,QString);
    void occRateLTC();
    void occRateCCC();
    void occRateAC(QString,QString ,QString,QString ,QString, QString );
    void sizeWL(QString,QString,QString);
    void waitingTime(QString,QString,QString);



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
