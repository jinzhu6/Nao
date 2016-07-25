#include "FirstSplitState.h"
#include "ColorIntensityMean.h"
#include <iostream>
FirstSplitState::FirstSplitState(vector<Feature*>* featureList,
                                 ClassifierState* succesivePositiveState,
                                 ClassifierState* successiveNegativeState)
{
    this->featureList = featureList;
    path = "resources/classifierStates/FirstColorState/";
    finalState = 0;
}

FirstSplitState::~FirstSplitState()
{
    //dtor
}


