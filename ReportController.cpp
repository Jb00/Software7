#include "ReportController.h"

ReportController* ReportController::anInstance =NULL;

ReportController::ReportController()
{
}

ReportController* ReportController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new ReportController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

void ReportController::setupHistogram()
{
    aHistogramReport = new Histogram();;
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->show();
    center(*aHistogramReport);
}

void ReportController::setupGraph()
{
    aGraphReport = new Graph();
    aGraphReport->setWindowTitle("Graph");
    aGraphReport->show();
    center(*aGraphReport);
}


//As the next following function are the same, we will use instead the following idea.
// from UI : Send a string, that will decide what if we will take.
// Stay like this for now, but unless xml is enormous we'll use what was proposed ^^.


void ReportController::occRateAC()
{
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40
    //Same than Mismatch but protocol will be different

    //NOT TESTED but assumed it would be the same

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}

void ReportController::occRateCCC()
{
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40
    //Same than Mismatch but protocol will be different

    //NOT TESTED but assumed it would be the same

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}

void ReportController::occRateLTC()
{
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40
    //Same than Mismatch but protocol will be different

    //NOT TESTED but assumed it would be the same

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}


void ReportController::mismatchCCCLTC(QList<Facility *> *aFacilityList)
{
    //If we want our facility then use our data.
    //And/or
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40

    //if (facilityWanted.constains(aFacilityList.first())
        //listId.append(our); listData.append(ourData);

 //   aFacilityList->first()->

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}

void ReportController::sizeWL()
{
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40

    //NOT TESTED But assumed to be correct

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}

void ReportController::waitingTime()
{
    //Ask protocol
    //Get Answer
    //In this example, we will try with 3 facilities, so 3 answers from protocol
    //Answer #1 for facility id = 1 : 350
    //Answer #2 for facility id = 2 :200
    //Answer #3 for facility id = 3 : 40

    //NOT TESTED But assumed to be correct

    listId.append("Phi");listId.append("Tau");listId.append("Pi"); //Add to lists , list O(1) to add and O(n) to read, good choice.
    listData.append(350);listData.append(175);listData.append(87);

    aHistogramReport = new Histogram();
    aHistogramReport->setWindowTitle("Histogram");
    aHistogramReport->setGeneralData(listId,listData); //Pass by reference
    aHistogramReport->show();
    center(*aHistogramReport);
}


void ReportController::center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 900;
  int HEIGHT = 900;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
}

