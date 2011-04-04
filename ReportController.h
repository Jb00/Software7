#ifndef REPORTCONTROLLER_H
#define REPORTCONTROLLER_H
#include "Histogram.h"
#include "Graph.h"
#include "Patient.h"
#include "Facility.h"
#include "MessageController.h"

#include <QDesktopWidget>
#include <QApplication>
#include <QList>

class ReportController
{

private :
    Histogram* aHistogramReport;
    Graph* aGraphReport;
    ReportController();
    static ReportController* anInstance;
    QList<QString> listId;
    QList<double> listData;
public:

    void center(QWidget &);
    void setupHistogram();
    void setupGraph();
    static ReportController* getInstance();
    void mismatchCCCLTC();
    void occRateLTC();
    void occRateCCC();
    void occRateAC();
    void sizeWL();
    void waitingTime();


};

#endif // REPORTCONTROLLER_H

