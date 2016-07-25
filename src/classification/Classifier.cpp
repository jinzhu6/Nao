#include "Classifier.h"

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
    state->storeValues();
}

float Classifier::test(){

    return (state->test("Red apple")+
            state->test("Yellow apple")+
            state->test("Glass")+
            state->test("Cup"))/4;
}

string Classifier::classify(Object& o){
    return state->classify(o);
}

void Classifier::showCurrentState(){
    state->showValues();
    state->showMeans();
}
