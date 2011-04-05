#include "waitinglistwindow.h"
#include "ui_waitinglistwindow.h"



WaitingListWindow::WaitingListWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WaitingListWindow)
{
    ui->setupUi(this);

    this->setPalette(Qt::white);

    connect(ui->cancelBtn, SIGNAL(pressed()), this, SLOT(cancelBtn_clicked()));
    connect(ui->addBtn, SIGNAL(pressed()), this, SLOT(addBtn_clicked()));
    connect(ui->searchBtn, SIGNAL(pressed()), this, SLOT(searchBtn_clicked()));
    connect(ui->removeBtn, SIGNAL(pressed()), this, SLOT(removeBtn_clicked()));

    aPatient = new Patient();

    setScheme();
}

WaitingListWindow::~WaitingListWindow()
{
    delete ui;
}

void WaitingListWindow::cancelBtn_clicked(){

    ui->fnameLbl->clear();
    ui->lnameLbl->clear();
    ui->facnameLbl->clear();
    ui->careLbl->clear();
    ui->cardNumLbl->clear();
    ui->waitingLbl->clear();
    ui->healthLine->clear();

    this->close();
}

void WaitingListWindow::addBtn_clicked(){

}

void WaitingListWindow::searchBtn_clicked(){


    ui->fnameLbl->clear();
    ui->lnameLbl->clear();
    ui->facnameLbl->clear();
    ui->careLbl->clear();
    ui->cardNumLbl->clear();
    ui->waitingLbl->clear();
    //ui->healthLine->clear();

    int card;
    card = ui->healthLine->text().toInt();
    aPatient = WaitingCtrl::getInstance()->searchForPatient(card);

    qDebug() << "The patient healthcard number is: " << aPatient->gethealthCard();
    if((!aPatient) || (ui->healthLine->text().isEmpty())){
        WaitingCtrl::getInstance()->invalid("Please enter a valid HC number.");
        ui->healthLine->clear();
    }
    else{

        QString hcard;
        hcard.setNum(aPatient->gethealthCard());


        if(aPatient->getNeeded() == 0)
            ui->careLbl->setText("Acute Needed");
        else if(aPatient->getNeeded() == 1)
            ui->careLbl->setText("Complex Needed");
        else
            ui->careLbl->setText("LTC Needed");



        ui->fnameLbl->setText(aPatient->getFName());
        ui->lnameLbl->setText(aPatient->getLName());
        ui->cardNumLbl->setText(hcard);
        ui->facnameLbl->setText(aPatient->getFacility());
        ui->waitingLbl->setText(aPatient->getDateWL().toString());
    }
}

void WaitingListWindow::removeBtn_clicked(){

    int card;
    card = ui->healthLine->text().toInt();

    if(!(ui->cardNumLbl->text().isEmpty()) && (ui->cardNumLbl->text().toInt() == card)){




        //qDebug() << "In remove btn clicked!";
        WaitingCtrl::getInstance()->removePatient(aPatient);
    }
    else{
        WaitingCtrl::getInstance()->invalid("Please enter a valid HC number.");
    }


}

void WaitingListWindow::keyPressEvent(QKeyEvent *event){

    switch(event->key()){

    case Qt::Key_Escape:
        this->close();
        break;
    }
}

void WaitingListWindow::setScheme(){

    QImage cross("red_cross2.png");

    ui->crossImg->setScaledContents(TRUE);
    ui->crossImg->setPixmap(QPixmap::fromImage(cross));

    QPalette btnPal(Qt::white);
    btnPal.setColor(QPalette::ButtonText, QColor(255, 255, 255));

    ui->addBtn->setStyleSheet("background-color: red");
    ui->removeBtn->setStyleSheet("background-color: red");
    ui->cancelBtn->setStyleSheet("background-color: red");
    ui->searchBtn->setStyleSheet("background-color: red");

    ui->addBtn->setPalette(btnPal);
    ui->removeBtn->setPalette(btnPal);
    ui->cancelBtn->setPalette(btnPal);
    ui->searchBtn->setPalette(btnPal);
}
