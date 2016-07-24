#include "Nao.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "Classifier.h"
#include "test.h"
#include "Object.h"


#include <iostream>
using namespace cv;
using namespace std;


Nao::Nao()
{
    init();
}

Nao::~Nao()
{
    //dtor
}

void Nao::init(){
    firstStateFeatList.push_back(&colorIntensityMean);
    glassCupSplitList.push_back(&shapeFeature);

    fss = FirstSplitState(&firstStateFeatList);
    gcs = GlassCupSplitState(&glassCupSplitList);

    classifier = Classifier(&fss);
}
void Nao::showObject(){
    lastDetectedObject.show();
}


void Nao::lookForObject(){
    Mat img = imread("resources/Cup.jpg",1);
    Object obj(img,"glassLBP");
    lastDetectedObject = obj;
}

void Nao::loadClassifier(){
    classifier.load();
}

bool Nao::classifyObject(){
    if(lastDetectedObject.img.data){
        return classifier.classify(lastDetectedObject);
    }else{
        cout << "No object found for classification" << endl;
        return 0;
    }
}


void Nao::trainClassifier(){
    classifier.train();
}

unsigned int Nao::testClassifier(){
    return classifier.test();
}

void Nao::showClassifierState(){
    classifier.showCurrentState();
}


