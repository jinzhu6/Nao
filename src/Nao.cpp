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


    gcs = GlassCupSplitState(&glassCupSplitList,&gs,&cs);
    as = ApplesState(&firstStateFeatList,&ra,&ya);
    fss = FirstSplitState(&firstStateFeatList,&as,&gcs);

    classifier = Classifier(&fss);
}
void Nao::showObject(){
    lastDetectedObject.show();
}


void Nao::lookForObject(){
    Mat img = imread("resources/YellowApple.jpg",1);
    Object obj(img,"object");
    lastDetectedObject = obj;
}

void Nao::loadClassifier(){
    classifier.load();
    classifier.setState(&this->gcs);
    classifier.load();
    classifier.setState(&this->as);
    classifier.load();
    classifier.setState(&this->fss);
}

string Nao::classifyObject(){
    if(lastDetectedObject.img.data){
        return classifier.classify(lastDetectedObject);
    }else{
        cout << "No object found for classification" << endl;
        return 0;
    }
}


void Nao::trainClassifier(){
    classifier.train();
    classifier.setState(&this->gcs);
    classifier.train();
    classifier.setState(&this->as);
    classifier.train();
    classifier.setState(&this->fss);
}

float Nao::testClassifier(){
    return classifier.test();
}

void Nao::showClassifierState(){
    classifier.showCurrentState();
}


