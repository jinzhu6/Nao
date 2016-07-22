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
        void train();
        void test();
        bool classify(Object& o);
        virtual ~Classifier();
        void setState(ClassifierState* clS);
    protected:
    private:
        ClassifierState* state;
};

#endif // CLASSIFIER_H
