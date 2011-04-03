#ifndef XMLREADER_H
#define XMLREADER_H
#include <QString>
#include <QXmlStreamReader>
#include "AssignHospitalController.h"
#include "AssignLTCController.h"
#include "AddBedController.h"
#include "AddWLController.h"
#include "Patient.h"
#include <QDateTime>


class XMLReader
{
public:
    XMLReader();
    ~XMLReader();
    QString xmlRequest;
    QString readRequest(QString request);

    //put these back under private after testing is done
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    void readRequestAmountOfBeds(QString xmlRequest);
    void readRequestMismatches(QString xmlRequest);
    void readRequestWaitTimes(QString xmlRequest);
    void readRequestWaitingListSize(QString xmlRequest);
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    //request data from other facilities
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    QString requestAmountOfBeds(QList<QString> facilityIDs, QString AC,QString CCC,QString LTC,QString requestID,QString startDate,QString endDate);
    QString requestMismatches(QList<QString> facilityIDs,QString typeOfBed,QString occupiedByBed,QString requestID,QString startDate,QString endDate);
    QString requestWaitTimes(QString requestID,QString startDate,QString endDate);
    QString requestWaitingListSize(QString requestID, QString startDate, QString endDate);
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    //rebuild stuff
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    QString rebuild();
    void readRebuild(QString rebuildRequest);
    QString buildWaitingListRecords();
    QString readRebuildRequest(QString rebuildRequest);
    QString buildRebuildResponse();
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    QString addOrDeletePatientToWaitingList(QString areaID, QString firstName,QString lastName,QString healthCardNumber,QString dateAdded,QString reqCare,QString occCare, QString AddOrDelete, bool remote);
    QString addOrDeleteToFacility(QString areaID,QString facilityID,QString firstName,QString lastName,QString healthCardNumber,QString dateAdded,QString reqCare,QString occCare, QString AddOrDelete, bool remote);
    QString addOrDeleteBeds(QString areaID, QString typeOfBed,QString facilityID, int amount, bool remote, QString addOrDelete);

private:
    QXmlStreamReader xml;

    //requests from other facilities
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    QString readAddorDeleteToFacility(QString item, QString addOrDelete);
    QString readAddorDeleteToWaitingList(QString item, QString addOrDelete);
    QString readAddRemoveBeds(QString item, QString type);
    QString reportBeds(QString aRequest);
    QString reportWaitingList(QString aRequest);
    QString reportWaitingListSize(QString aRequest);
    QString xmlHeader;
    QString buildResponseID(QString ID);
    QString buildResponseDate(QString startdate, QString enddate);
    void readReportWaitingLisSizeResponse(QString aRequest);
    QString buildFacilityRecord(QString AC, QString CCC , QString LTC, QString date);
    QString buildFacilityRecordDifference(QString ACT, QString CCCT, QString LTCT, QString AC, QString CCC , QString LTC, QString date);
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    //responses to the requests from other facilities
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////
    QString buildBedReportResponse(QString requestID, QString CCC,QString AC,QString LTC,QString startDate,QString endDate);
    QString buildWaitingListResponse(QString requestID,QString reportStartDate,QString reportEndDate);
    QString buildWaitingListRecord(QString dte_added, QString dte_admitted);
    QString buildWaitingListSizeRecord(QString date);
    QString buildWaitingListSizeResponse(QString requestID, QString reportStartDate, QString reportEndDate);
    QString buildBedMismatchReportResponse(QString requestID, QString CCC, QString AC, QString LTC,QString startDate,QString endDate, QString type);
    QString buildFacilityMismatchRecord(QString AC,QString  CCC, QString LTC,QString type, QString startDate);
    QString buildFacilityMismatchDifference(QString occCare,QString reqCare,QString datePlacedOnWaitingList,QString AC,QString CCC,QString LTC,QString date, QString type);
    /////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////

    //reading responses from other facilities

    QString buildRequestID(QString ID);

};

#endif // XMLREADER_H
