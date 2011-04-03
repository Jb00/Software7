#ifndef GRAPH_H
#define GRAPH_H

#include <QPainter>
#include <QWidget>
#include <QWidget>
#include<QDebug>

class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(QWidget *parent = 0);

protected :
        void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // GRAPH_H
