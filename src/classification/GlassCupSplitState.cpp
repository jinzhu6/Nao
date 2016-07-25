//
//  GlassCupSplitState.cpp
//
//
//  Created by Alessandro Imbrenda on 23/07/16.
//
//

#include "GlassCupSplitState.hpp"
#include "ColorIntensityMean.h"
#include <iostream>
GlassCupSplitState::GlassCupSplitState(vector<Feature*>* featureList,
                    ClassifierState* sps,
                    ClassifierState* sns)
{
    this->featureList = featureList;
    this->succesivePositiveState = sps;
    this->successiveNegativeState = sns;
    path = "resources/classifierStates/GlassCupSplitState/";
    finalState = 0;
}

GlassCupSplitState::~GlassCupSplitState()
{
    //dtor
}

