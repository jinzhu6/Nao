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
    if(argc != 2) return 0;

    Mat img = imread(argv[1],1);
    Object obj(img,"glassLBP");

    obj.preTreat();
    obj.show();
    LocalBinaryPattern lbp = LocalBinaryPattern();
    ColorIntensityMean cim = ColorIntensityMean();
    cout << obj.extract_feature(cim) << endl;
    Nao nao;
    nao.lookForObject();
    //nao.showObject();
    string path = "resources/classifierStates/FirstColorState/colored/train";
    vector<Feature*> featList;
    featList.push_back(&cim);
    FirstSplitState fss(featList);

    nao.trainClassifier(&fss,path);

    waitKey(0);
    return 0;
}
