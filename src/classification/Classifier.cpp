#include "Classifier.h"
#define POSITIVE 1
#define NEGATIVE 0


Classifier::Classifier()
{
}

Classifier::~Classifier()
{
    //dtor
}
Classifier::Classifier(ClassifierState* state){
    setState(state);
}

void Classifier::setState(ClassifierState* clS){
    this->state = clS;
}
void Classifier::load(){
    state->loadValues();
}
void Classifier::train(){
    state->train("positive");
    state->train("negative");
}
void Classifier::test(){

}
bool Classifier::classify(Object& o){

}

void Classifier::showCurrentState(){
    state->showValues();
    state->showMeans();
}
