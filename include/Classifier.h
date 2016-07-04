#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "StateClassifier.h"
#include "StartState.h"


using namespace std;

class Classifier
{
    public:
        Classifier();
        Classifier(char* trainingPath,char* testingPath):trainingPath(trainingPath),testingPath(testingPath){};
        virtual ~Classifier();
    protected:
    private:
        char* trainingPath;
        char* testingPath;
        StateClassifier* state;

};

#endif // CLASSIFIER_H
