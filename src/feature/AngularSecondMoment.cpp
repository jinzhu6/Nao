#include "AngularSecondMoment.h"
#include <iostream>

using namespace std;

AngularSecondMoment::AngularSecondMoment()
{
    //ctor
}

AngularSecondMoment::~AngularSecondMoment()
{
    //dtor
}


int AngularSecondMoment::extractIn(Mat& img)
{
    int c = 0;
    int x = 0;
    int y = 0;
    for(; y < img.rows; y++)
    {
        for(x = 0; x < img.cols; x++)
        {
            img.at<uchar>(y,x)+0.0;
        }
    }
    return 0;
}
