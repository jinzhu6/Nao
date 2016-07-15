/*
 * main.cpp
 *
 *  Created on: 29 juin 2016
 *      Author: Emmanuel
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "Classifier.h"
#include "test.h"
#include "Object.h"
#include "LocalBinaryPattern.h"
#include "AngularSecondMoment.h"
#include "ColorIntensityMean.h"

#include <iostream>
using namespace cv;
using namespace std;




/** @function main */
int main( int argc, char** argv )
{
    if(argc != 2) return 0;

    Mat img = imread(argv[1],1);
    Object obj(img,"redAppleLBP");

    obj.preTreat();
    obj.show();
    LocalBinaryPattern lbp = LocalBinaryPattern();
    ColorIntensityMean cim = ColorIntensityMean();
    cout << obj.extract_feature(lbp) << endl;
    obj.showComputed();
    obj.saveResult();
    waitKey(0);

    return 0;
}

