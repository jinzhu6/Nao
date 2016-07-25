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

    Nao nao;

    //*********** Lanching **************//
    //nao.trainClassifier();
    nao.loadClassifier();
    //nao.showClassifierState();
    nao.lookForObject();
    nao.showObject();
    //nao.testClassifier();
    cout << "object found is of type : " << nao.classifyObject() << endl;

    waitKey(0);
    return 0;
}
