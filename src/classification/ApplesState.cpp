#include "ApplesState.h"

ApplesState::ApplesState(vector<Feature*>* featureList,
                         ClassifierState* sps,
                         ClassifierState* sns)

{
    this->succesivePositiveState = sps;
    this->successiveNegativeState = sns;
    this->featureList = featureList;
    path = "resources/classifierStates/ApplesState/";
    finalState = 0;

}

ApplesState::~ApplesState()
{
    //dtor
}
