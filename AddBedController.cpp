#include "AddBedController.h"
#include "mapwinctrl.h"


AddBedController* AddBedController::anInstance = NULL; // Global static pointer used to ensure a single instance of the class.



AddBedController::AddBedController()
{
}

AddBedController* AddBedController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddBedController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void AddBedController::addtoBed(QString aNumberBed, QString aType, Facility *aFacility)
{

    bool ok; //to make sure the conversion String to number Worked;
    int numberBedInt; //To hold the String to int
    QString numberBed = aNumberBed;

 //   QString type = typeid(*aFacility).name();
 //   std::cout <<'\n'<< typeid(aFacility).name();


    numberBedInt = numberBed.toInt(&ok);

    //Verify if it is a integer. If it isn't, return -1;
    if (!ok)
    {
        return;
    }

    if(aType == "Acute")
    {
        if (numberBedInt < 0)
        {
            if(!aFacility->removeBedAcute(numberBedInt))
                return; //invalid
        }
        else
        {
            for (int i=0; i< numberBedInt ; i++)
            {
                aFacility->addBedAcute();
            }
        }
    }
    else
        if(aType == "Complex")
        {
            if (numberBedInt < 0) //Negative
            {
                if(!aFacility->removeBedComplex(numberBedInt))
                    return;
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility->addBedComplex();
                }
            }
        }
    else
        if(aType == "LTC")
        {
            if (numberBedInt < 0)
            {
                if(!aFacility->removeBedLTC(numberBedInt))
                    return;
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility->addBedLTC();
                }
            }
        }
}

void AddBedController::addBedXML(QString anId, QString anAC,QString aCCC,QString aLTC, QString aType)
{
    //First convert them into int
    //Then find facility
    //Then add/Delete
    //Then verify if we talk about our facility.

    int AC,CCC,LTC;
    AC =anAC.toInt();
    CCC = aCCC.toInt();
    LTC = aLTC.toInt();

    Facility * aFacility;

    aFacility =  MapWinCtrl::getInstance()->getFacilityFromid(anId); //Will have to check if null or empty.

    if (aType == "Add")
    {
        if (AC > 0)
        {
            for (int i=0; i< AC ; i++)
            {
                aFacility->addBedAcute();
            }
        }
        else
            if (CCC > 0)
            {
                for (int i=0; i< CCC ; i++)
                {
                    aFacility->addBedComplex();
                }
            }
            else
                if(LTC > 0)
                {
                    for (int i=0; i< LTC ; i++)
                    {
                        aFacility->addBedLTC();
                    }
                }
     }
    else //Then delete beds
    {
        if (AC > 0)
        {
                AC = AC *-1 ; //Make it negative
                if(!aFacility->removeBedAcute(AC))
                    return; //invalid
        }
        else
            if (CCC > 0)
            {
                CCC = CCC *-1 ; //Make it negative
                if(!aFacility->removeBedComplex(CCC))
                    return; //invalid
            }
            else
                if(LTC > 0)
                {
                    LTC =LTC *-1 ; //Make it negative
                    if(!aFacility->removeBedLTC(LTC))
                        return; //invalid
                }
        }

    //To add to the DB if it is our facility
    if (anId.toInt() == MapWinCtrl::getInstance()->getId())
    {
        qDebug() <<"in db";
        QSqlQuery query;
        QString queryText;

        //the main insert script
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        query.exec(QLatin1String("INSERT INTO facility SET AC =AC +1"));
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    }
}




