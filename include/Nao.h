#ifndef NAO_H
#define NAO_H
#include "Classifier.h"
#include "ObjectExtractor.h"
#include "Object.h"
#include "ClassifierState.h"


class Nao
{
    public:
        Nao();
        Nao(ClassifierState* cls);
        virtual ~Nao();
        void lookForObject();
        void showObject();
        void trainClassifier(ClassifierState* clS, const string& trainPath);
        unsigned int testClassifier(ClassifierState* clS, const string& testPath);

    protected:
    private:
        ObjectExtractor objectExtractor;
        Classifier classifier;
        Object lastDetectedObject;
};

#endif // NAO_H
