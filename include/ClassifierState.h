#ifndef CLASSIFIERSTATE_H
#define CLASSIFIERSTATE_H

#include <vector>
#include "Feature.h"

// state classes that contains the features
class ClassifierState
{
    public:
        ClassifierState();
        virtual ~ClassifierState();
        virtual void storeValues();
        virtual void loadValues();
        virtual void train(const string& path);
        virtual unsigned int test();
    protected:
        string storingPath;
        vector<Feature*> featureList;
        vector< vector<unsigned int> > valueList;

    private:
};

#endif // CLASSIFIERSTATE_H
