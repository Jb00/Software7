#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "mapwinctrl.h"
#include "MessageController.h"

MapWindow::MapWindow(const QString &filePath): ui(new Ui::MapWindow)
{
    renderer = new QSvgRenderer(filePath);

    ui->setupUi(this);
    this->setMouseTracking(true);

    ui->menuFile->addAction(ui->actionLogout);
    ui->menuAdmin->addAction(ui->actionAdd_newUser);
    ui->menuAdmin->addAction(ui->actionCreate_Facility);
    ui->menuReport->addAction(ui->actionGenerate);
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAdd_newUser, SIGNAL(triggered()), this, SLOT(createUser_clicked()));
    connect(ui->actionCreate_Facility, SIGNAL(triggered()), this, SLOT(createFac_clicked()));
    connect(ui->actionFacilityView,SIGNAL(triggered()), this, SLOT(facilityView()));
   // connect(ui->actionAbout,SIGNAL(triggered()), this, SLOT(reportSetup()));
    connect(ui->actionGenerate, SIGNAL(triggered()), this, SLOT(generateReport_clicked()));

    colorList = new QList<QColor>();
    facSizeList = new QList<int>();
}

MapWindow::~MapWindow(){delete ui;}

void MapWindow::generateReport_clicked(){MapWinCtrl::getInstance()->goToGenerate();}


void MapWindow::createUser_clicked(){MapWinCtrl::getInstance()->goToAddUser();}

void MapWindow::createFac_clicked(){
    QPoint aPnt;
    QColor aColor;
    MapWinCtrl::getInstance()->goToAddFac(aPnt, NULL, aColor);
}







void MapWindow::facilityView()
{








    MapWinCtrl::getInstance()->gotoFacility();
}


void MapWindow::paintEvent(QPaintEvent *event)
 {
     Q_UNUSED(event)
     QPainter painter(this);
     renderer->render(&painter);

     int innerSize;
     int outerSize;

     if(!(MapWinCtrl::getInstance()->listOfFacility.isEmpty())){




         for(int i = 0; i < MapWinCtrl::getInstance()->listOfFacility.size(); i++){









             QPoint aPnt;
             aPnt.setX(MapWinCtrl::getInstance()->listOfFacility.at(i)->getX());
             aPnt.setY(MapWinCtrl::getInstance()->listOfFacility.at(i)->getY());












             if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= 0
                && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()){



                 outerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()) * 5);
                 innerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()) * 5)/2;


                 if(outerSize > 10){
                     outerSize = 10;
                     innerSize = 5;
                 }
                 if(outerSize < 4){
                     outerSize = 4;
                     innerSize = 2;
                 }
                QColor temp;
                QColor temp2;


                int outer;
                int inner;







                outer = (MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAcute() - MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute()) * 0.1;




                inner = (MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeComplex() - MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex()) * 0.1;





                qDebug() << "getSizeAvailableAcute() = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute();
                qDebug() << "J.B. Number occupied AC: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAcute();
                qDebug() << "getSizeAvailableComplex() = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex();
                qDebug() << "J.B. Number occupied CCC" << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeComplex();



                temp.setRgb(outer, 255 - outer, 0, 255);
                temp2.setRgb(inner, 255 - inner, 0, 255);

                 painter.setBrush(temp);
                 painter.setPen(temp);




                 painter.drawEllipse(aPnt, outerSize, outerSize);


                 painter.setBrush(temp2);
                 painter.setPen(temp2);
                 painter.drawEllipse(aPnt, innerSize, innerSize);
             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= 0
                && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() < MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()){


                 innerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()) * 5)/2;
                 outerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()) * 5);


                 if(outerSize > 10){
                     outerSize = 10;
                     innerSize = 5;
                 }
                 if(outerSize < 4){
                     outerSize = 4;
                     innerSize = 2;
                 }







                 QColor temp;
                 QColor temp2;


                 int outer;
                 int inner;


                 inner = (MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAcute() - MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute()) * 0.1;
                 outer = (MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeComplex() - MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex()) * 0.1;



                 temp.setRgb(outer, 255 - outer, 0, 255);
                 temp2.setRgb(inner, 255 - inner, 0, 255);

                  painter.setBrush(temp);
                  painter.setPen(temp);
                  painter.drawEllipse(aPnt, outerSize, outerSize);



                  painter.setBrush(temp2);
                  painter.setPen(temp2);
                  painter.drawEllipse(aPnt, innerSize, innerSize);
             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > 0
                     && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/4){

                 painter.setBrush(Qt::black);
                 painter.setPen(Qt::black);
                 painter.drawEllipse(aPnt, 4, 4);









             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/4
                     && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/2){


                 painter.setBrush(Qt::black);
                 painter.setPen(Qt::black);
                 painter.drawEllipse(aPnt, 6, 6);




             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/2
                     && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC()) * 3)/4){



                 painter.setBrush(Qt::black);
                 painter.setPen(Qt::black);

                 painter.drawEllipse(aPnt, 8, 8);





             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC()) * 3)/4){





                 painter.setBrush(Qt::black);
                 painter.setPen(Qt::black);
                 painter.drawEllipse(aPnt, 10, 10);


             }
             else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute() == MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex()){




                 if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > 0
                         && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC())/4){




                     painter.setPen(Qt::DashLine);
                     painter.setBrush(Qt::blue);
                     painter.setPen(Qt::black);
                     painter.drawEllipse(aPnt, 4, 4);



                 }
                 else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC())/4
                         && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC())/2){




                     painter.setPen(Qt::DashLine);
                     painter.setBrush(Qt::blue);
                     painter.setPen(Qt::black);
                     painter.drawEllipse(aPnt, 6, 6);

                 }

                 else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC())/2
                         && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() <= ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()) * 3)/4){

                     painter.setPen(Qt::DashLine);
                     painter.setBrush(Qt::blue);
                     painter.setPen(Qt::black);
                     painter.drawEllipse(aPnt, 8, 8);




                 }





                 else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()) * 3)/4){





                     painter.setPen(Qt::DashLine);
                     painter.setBrush(Qt::blue);
                     painter.setPen(Qt::black);
                     painter.drawEllipse(aPnt, 10, 10);

                 }
             }


         }
     }


 }


void MapWindow::keyPressEvent(QKeyEvent *event){

    switch(event->key()){

    case Qt::Key_Escape:
        qApp->quit();
        break;

    }
}

void MapWindow::mousePressEvent(QMouseEvent *event){


    QPixmap pm = QPixmap::grabWidget(this);
    QImage test;

    test = pm.toImage();

    QColor currentColor = test.pixel(event->x(), event->y());
    qDebug() << currentColor;

    int outerSize;
    int innerSize;

    for(int i = 0; i < MapWinCtrl::getInstance()->listOfFacility.size(); i++){

        if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() > MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()){

            outerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()) * 5);
            if(outerSize > 10)
                outerSize = 10;
        }
        else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC() < MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()){

            outerSize = ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalCCC()/MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalAC()) * 5);
            if(outerSize > 10)
                outerSize = 10;
        }
        else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > 0
                && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/4)
            outerSize = 4;
        else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/4
                && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/2)
            outerSize = 6;
        else if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() > (MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC())/2
                && MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC() <= ((MapWinCtrl::getInstance()->listOfFacility.at(i)->getTotalLTC()) * 3)/4)
            outerSize = 8;
        else
            outerSize = 10;

        if(event->pos().x() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getX() + outerSize)
           && event->pos().x() >= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getX() - outerSize)
            && event->pos().y() >= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getY() - outerSize)
            && event->pos().y() <= (MapWinCtrl::getInstance()->listOfFacility.at(i)->getX() + outerSize)){

            MapWinCtrl::getInstance()->invalid();

            return;
        }

    }

    if(currentColor == QColor("#f2f1f0"))
        MapWinCtrl::getInstance()->invalid();
    else
        MapWinCtrl::getInstance()->goToAddFac(event->pos(), area, currentColor);


    update();
}

