#ifndef CLASSIFIERSTATE_H
#define CLASSIFIERSTATE_H

#include <vector>
#include "Feature.h"
#include "Object.h"

// state classes that contains the features
class ClassifierState
{
    public:
        ClassifierState();
        virtual ~ClassifierState();
        virtual void storeValues();
        virtual void loadValues();
        virtual void train(const string& type);
        virtual unsigned int test();
        virtual void showValues();
        virtual void showMeans();
        virtual void classify(Object &object);
        virtual void compareToMean(vector<unsigned int>& valueList);
    protected:
        string path;
        vector<Feature*> featureList;
        vector< vector<unsigned int> > positiveValueList;
        vector< vector<unsigned int> > negativeValueList;
        vector<unsigned int> positiveMeans;
        vector<unsigned int> negativeMeans;

        void computeMeans();
    private:


};

#endif // CLASSIFIERSTATE_H
