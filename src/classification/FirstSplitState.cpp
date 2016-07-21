#include "FirstSplitState.h"
#include "ColorIntensityMean.h"
#include <iostream>
FirstSplitState::FirstSplitState(vector<Feature*> featureList)
{
    this->featureList = featureList;
    storingPath = "resources/classifierStates/FirstColorState/values/";
}

FirstSplitState::~FirstSplitState()
{
    //dtor
}


