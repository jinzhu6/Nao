#include "Classifier.h"

Classifier::Classifier()
{
}

Classifier::~Classifier()
{
    //dtor
}


void Classifier::setState(ClassifierState* clS){
    this->state = clS;
}
