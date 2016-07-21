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
        void trainClassifier(ClassifierState* clS, string& trainPath);
        unsigned int testClassifier(ClassifierState* clS, string& testPath);

    protected:
    private:
        ObjectExtractor objectExtractor;
        Classifier classifier;
        Object lastDetectedObject;
};

#endif // NAO_H
