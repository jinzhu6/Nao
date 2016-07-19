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
    for(int y = 0; y < img.rows; y++)
    {
        for(int x = 0; x < img.cols; x++)
        {
            img.at<uchar>(y,x)+0.0;
        }
    }
    return 0;
}
