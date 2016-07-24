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
GlassCupSplitState::GlassCupSplitState(vector<Feature*>* featureList)
{
    this->featureList = featureList;
    path = "resources/classifierStates/GlassCupSplitState/";
}

GlassCupSplitState::~GlassCupSplitState()
{
    //dtor
}

