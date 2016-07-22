#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "ClassifierState.h"
#include "Object.h"

using namespace std;

class Classifier
{
    public:
        Classifier();
        Classifier(ClassifierState* clS);
        //Classifier(char* trainingPath,char* testingPath):trainingPath(trainingPath),testingPath(testingPath){};
        void load();
        void train();
        unsigned int test();
        bool classify(Object& o);
        virtual ~Classifier();
        void setState(ClassifierState* clS);
        void showCurrentState();
    protected:
    private:
        ClassifierState* state;
};

#endif // CLASSIFIER_H
