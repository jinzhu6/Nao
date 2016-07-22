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
#include <iostream>

#include "Classifier.h"
#include "test.h"
#include "Object.h"
#include "LocalBinaryPattern.h"
#include "ColorIntensityMean.h"
#include "FirstSplitState.h"
#include "Nao.h"


using namespace cv;
using namespace std;



/** @function main */
int main(int argc, char* argv[] )
{
    //****** init classification *******//


    vector<Feature*> featList;
    ColorIntensityMean cim = ColorIntensityMean();
    featList.push_back(&cim);
    FirstSplitState fss(featList);
    Classifier classifier(&fss);
    Nao nao(&classifier);

    //*********** Lanching **************//

    nao.trainClassifier();
    //fss.loadValues();
    fss.showValues();
    //fss.computeMeans();
    fss.showMeans();
    //nao.testClassifier();
    if(argc != 2) return 0;

    Mat img = imread(argv[1],1);
    Object obj(img,"glassLBP");

    obj.preTreat();
    obj.show();
    cout << obj.extract_feature(cim) << endl;
    nao.lookForObject();
    //nao.showObject();


    waitKey(0);
    return 0;
}
