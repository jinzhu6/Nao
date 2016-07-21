#include "Nao.h"
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


Nao::Nao()
{


}

Nao::~Nao()
{
    //dtor
}

Nao::Nao(ClassifierState* cls){
    classifier.setState(cls);
}

void Nao::showObject(){
    lastDetectedObject.show();
}


void Nao::lookForObject(){
    Mat img = imread("resources/Glass.jpg",1);
    Object obj(img,"glassLBP");
    lastDetectedObject = obj;
}


void Nao::trainClassifier(ClassifierState* clS,string &trainPath){
    clS->train(trainPath, "positive");
    clS->train(trainPath, "negative");
    clS->storeValues();
}

unsigned int Nao::testClassifier(ClassifierState* clS, string &testPath){
    unsigned int pourcentage = 0;


    return pourcentage;
}

void Nao::showClassifierState(ClassifierState* clS){
    clS->showValues();
}


