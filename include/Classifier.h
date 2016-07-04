#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include "StateClassifier.h"
#include "StartState.h"

class Classifier
{
    public:
        Classifier();
        virtual ~Classifier();
    protected:
    private:
        StateClassifier* state;

};

#endif // CLASSIFIER_H
