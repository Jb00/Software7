#include "mapwindow.h"
#include "ui_mapwindow.h"

MapWindow::MapWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    QImage img("map2.png");

    ui->setupUi(this);
    ui->mapImg->setScaledContents(TRUE);
    ui->mapImg->setPixmap(QPixmap::fromImage(img));
    //aMap = new QGoogleMap(this);
    //aMap->show();

    ui->menuFile->addAction(ui->actionLogout);
    ui->menuAdmin->addAction(ui->actionAdd_newUser);
    ui->menuAdmin->addAction(ui->actionCreate_Facility);
    connect(ui->actionLogout, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionAdd_newUser, SIGNAL(triggered()), this, SLOT(createUser_clicked()));
    connect(ui->actionCreate_Facility, SIGNAL(triggered()), this, SLOT(createFac_clicked()));
    connect(ui->actionFacilityView,SIGNAL(triggered()), this, SLOT(facilityView()));
    connect(ui->actionAbout,SIGNAL(triggered()), this, SLOT(reportSetup()));
    MapWinCtrl::getinstance();
}

MapWindow::~MapWindow(){delete ui;}

void MapWindow::createUser_clicked(){MapWinCtrl::getinstance()->goToAddUser();}

void MapWindow::createFac_clicked(){MapWinCtrl::getinstance()->goToAddFac();}

void MapWindow::keyPressEvent(QKeyEvent *event){

    switch(event->key()){

    case Qt::Key_Escape:
        qApp->quit();
        break;
    }
}

void MapWindow::facilityView()
{
    MapWinCtrl::getinstance()->gotoFacility();
}

void MapWindow::reportSetup()
{
    QList<QString> listResponse;
    QList<QString> listFacilityDemanded;
    listFacilityDemanded <<"test" << "Test2";
    QString type ="AC";
    QDate aDateB(1990,5,12);
    QDate aDateA(1994,5,12);
    listResponse = MessageController::getInstance()->setGetData(listFacilityDemanded,type,aDateB,aDateA);
    qDebug() << listResponse.size();
}

