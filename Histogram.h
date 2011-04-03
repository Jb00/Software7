#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <QPainter>
#include <QWidget>
#include <QList>
#include <QDebug>
#include <QString>
#include <QMutableListIterator> //Used to modify a Qlist as Iterator


class Histogram : public QWidget
{
    Q_OBJECT

public:
    Histogram(QWidget *parent = 0);
    void setGeneralData(QList<QString> , QList<double> );
 //   ~Histogram();
protected :
    void paintEvent(QPaintEvent *);


private:

    QList<QString> facilityList;
    QList<double> data;


};

#endif // HISTOGRAM_H
