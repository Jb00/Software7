#include "waitingctrl.h"
#include "mapwinctrl.h"

WaitingCtrl* WaitingCtrl::anInstance = NULL;

WaitingCtrl::WaitingCtrl(){aPatient = new Patient();}

WaitingCtrl* WaitingCtrl::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new WaitingCtrl; //Create a new instance, new for the heap.

    return anInstance;//Return tAddFacCtrlhe instance.
}

void WaitingCtrl::invalid(QString message){

    invalidWin = new InvalidWindow();

    invalidWin->setLabelText(message);
    invalidWin->show();

    genCTRL::center(*invalidWin);
}

void WaitingCtrl::removePatient(Patient *thePatient){

    qDebug() << "thePatient healthCard: " << thePatient->gethealthCard();
    for(int i = 0; i < MapWinCtrl::getInstance()->listOfFacility.size(); i++){

        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->isEmpty())){

            for(int j = 0; j < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientComplex(); j++){
                if((MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard() == thePatient->gethealthCard())
                && (!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->getDateWL().isNull()))){

                    qDebug() << "HealthCard in removePatient complex: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard();
                    MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientWL(thePatient->gethealthCard());
                    MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->setdateWL(QDateTime::currentDateTime());

                    qDebug() << "thePatient needed: " << thePatient->getNeeded();
                    if(thePatient->getNeeded() == 0){

                        qDebug() << "Size of complex patient list before remove = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->size();
                        qDebug() << "Number of available beds in complex care before remove = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex();
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientComplex(thePatient->gethealthCard());
                        qDebug() << "Size of complex patient list after remove = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->size();
                        qDebug() << "Number of available beds in complex care after remove = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableComplex();


                        qDebug() << "Size of acute patient list before add = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->size();
                        qDebug() << "Number of available beds in acute care before add = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute();
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->addPatientAcute(thePatient);
                        qDebug() << "Size of acute patient list after add = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->size();
                        qDebug() << "Number of available beds in acute care after add = " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizeAvailableAcute();
                        break;
                    }
                    else if(thePatient->getNeeded() == 3){
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientComplex(thePatient->gethealthCard());
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->addPatientLTC(thePatient);
                        break;
                    }

                }
            }
        }
        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->isEmpty())){

            for(int j = 0; j < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientAcute(); j++){
                if((MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(j)->gethealthCard() == thePatient->gethealthCard())
                &&(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(j)->getDateWL().isNull()))){

                    qDebug() << "HealthCard in removePatient acute: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(j)->gethealthCard();
                    MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientWL(thePatient->gethealthCard());
                    MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(j)->setdateWL(QDateTime::currentDateTime());

                    if(thePatient->getNeeded() == 1){
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientAcute(thePatient->gethealthCard());
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->addPatientComplex(thePatient);
                        break;
                    }
                    else if(thePatient->getNeeded() == 3){
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->removePatientAcute(thePatient->gethealthCard());
                        MapWinCtrl::getInstance()->listOfFacility.at(i)->addPatientLTC(thePatient);
                        break;
                    }
                }
            }
        }
        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->isEmpty())){

            for(int j = 0; j < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientLTC(); j++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(j)->gethealthCard() == thePatient->gethealthCard()){

                    break;
                }
            }

        }
    }
}

Patient* WaitingCtrl::searchForPatient(int health){

    for(int i = 0; i < MapWinCtrl::getInstance()->listOfFacility.size(); i++){

        qDebug() << "Size of complex: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientComplex();
        qDebug() << "Size of Acute: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientAcute();
        qDebug() << "Size of LTC: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientLTC();

        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->isEmpty())){

            for(int j = 0; j < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientComplex(); j++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j);
                    qDebug() << "Health card number inside Waiting Ctrl: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListComplex()->at(j)->gethealthCard();
                    return aPatient;
                }
            }
        }
        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->isEmpty())){

            for(int k = 0; k < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientAcute(); k++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k);
                    qDebug() << "Health card number inside Waiting Acute: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListAcute()->at(k)->gethealthCard();
                    return aPatient;
                }
            }
        }
        if(!(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->isEmpty())){

            for(int l = 0; l < MapWinCtrl::getInstance()->listOfFacility.at(i)->getSizePatientLTC(); l++){
                if(MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l)->gethealthCard() == health){

                    aPatient = MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l);
                    qDebug() << "Health card number inside Waiting LTC: " << MapWinCtrl::getInstance()->listOfFacility.at(i)->getListLTC()->at(l)->gethealthCard();
                    return aPatient;
                }
            }

        }

    }

}
