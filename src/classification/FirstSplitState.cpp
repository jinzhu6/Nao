#include "FirstSplitState.h"
#include "ColorIntensityMean.h"
#include <iostream>
FirstSplitState::FirstSplitState(vector<Feature*>* featureList,
                                 ClassifierState* sps,
                                 ClassifierState* sns)
{
    this->succesivePositiveState = sps;
    this->successiveNegativeState = sns;
    this->featureList = featureList;
    path = "resources/classifierStates/FirstColorState/";
    finalState = 0;
}

FirstSplitState::~FirstSplitState()
{
    //dtor
}


