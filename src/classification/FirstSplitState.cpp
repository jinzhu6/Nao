#include "FirstSplitState.h"
#include "ColorIntensityMean.h"
#include <iostream>
FirstSplitState::FirstSplitState(vector<Feature*>* featureList)
{
    this->featureList = featureList;
    path = "resources/classifierStates/FirstColorState/";
}

FirstSplitState::~FirstSplitState()
{
    //dtor
}


