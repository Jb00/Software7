#include "Graph.h"

Graph::Graph(QWidget *parent) :
    QWidget(parent)
{
}

void Graph::paintEvent(QPaintEvent *event)
{
    int maxY =500;
    int constantY = 650/10; //Needed for text for Y axis as a constant
    int textY =constantY-15; //Needed for text for Y axis to maintain number
    QPen pen(Qt::black,2,Qt::SolidLine);
    QPainter p(this);
    p.setPen(pen); //Set the pen we just declare

    p.drawLine(50,700,700,700); //X line
    p.drawLine(50,700,50,50); //Y line
    p.drawText(30,700,"0"); // 0 line

    //Precision line + text for Y Axis
    //We will use 10 lines
    //Text will be decided like the following : constantY = maxY / 10
    //Then increase by constant 10 times.

    p.drawLine(45,textY,50,textY); //Precision line Y
    p.drawText(20,textY,"1");    //Text for line
    textY = textY+constantY;
    p.drawLine(45,textY,50,textY); //Precision line Y
    p.drawText(20,textY,"1");    //Text for line
    textY = textY+constantY;
    p.drawLine(45,textY,50,textY); //Precision line Y
    p.drawText(20,textY,"1");    //Text for line
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y
    textY = textY+constantY;
    p.drawText(20,textY,"1");    //Text for line
    p.drawLine(45,textY,50,textY); //Precision line Y


    //Precision line + text for X Axis+
    //

    //For the point, we will use the following idea.
    //Set all points in an array and transform them into 700-Number so they fit in the graph O(n)
    //Draw point 1.
    //For all the remaining point, draw the point, and the line (1,point[i-1],2,point[i])
    //for i =1; i<array.size() ;i++

    int point [] = { 686, 698,500, 620,200  }; //Step 1
    int size =sizeof(point) / sizeof(int); //Get size of the array
    int constantX = 40;
    int xNow =55;
    int xLast = 55;

    p.drawPoint(xNow,point[0]); //First point
    for (int i=1;i<size;i++)
    {
        xNow=xNow+constantX;
        p.drawPoint(xNow,point[i]);
        p.drawLine(xLast,point[i-1],xNow, point[i]);
        xLast =xLast +constantX;
    }
}
