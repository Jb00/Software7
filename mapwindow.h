#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include "mapwinctrl.h"
#include <QWidget>
#include <QString>
#include <QSvgRenderer>
#include <QSize>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QRgb>


//TEST REPORT QLIST
#include <QList>
#include <QString>

namespace Ui {
    class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(const QString& filePath);
    ~MapWindow();

    void keyPressEvent(QKeyEvent * event);

    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    void determineFacColor();
    void determineFacSize();

private:
    QList<QString> listResponse;

    Ui::MapWindow *ui;
    QString fileName;
    QSvgRenderer* renderer;
    QList<int> *facSizeList;
    QList<QColor> *colorList;
    int area;


private slots:

    void createUser_clicked();
    void createFac_clicked();
    //void logout_clicked();
    void facilityView();
    //void reportSetup();
    void generateReport_clicked();
};


#endif // MAPWINDOW_H

