#include "ApplesState.h"

ApplesState::ApplesState(vector<Feature*>* featureList,
                         ClassifierState* succesivePositiveState,
                         ClassifierState* successiveNegativeState)
{
    this->featureList = featureList;
    path = "resources/classifierStates/ApplesState/";
    finalState = 0;
}

ApplesState::~ApplesState()
{
    //dtor
}
