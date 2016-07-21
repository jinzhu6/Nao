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
        //virtual void loadValuesByType(const string& type);
        virtual void train(string path, const string& type);
        virtual unsigned int test();
        virtual void showValues();
    protected:
        string storingPath;
        vector<Feature*> featureList;
        vector< vector<unsigned int> > positiveValueList;
        vector< vector<unsigned int> > negativeValueList;


    private:
};

#endif // CLASSIFIERSTATE_H
