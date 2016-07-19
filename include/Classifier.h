#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "ClassifierState.h"
#include "FirstSplitState.h"


using namespace std;

class Classifier
{
    public:
        Classifier();
        Classifier(char* trainingPath,char* testingPath):trainingPath(trainingPath),testingPath(testingPath){};
        virtual ~Classifier();
        void setState(ClassifierState* clS);
    protected:
    private:
        string trainingPath;
        string testingPath;
        ClassifierState* state;
};

#endif // CLASSIFIER_H
