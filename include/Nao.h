#ifndef NAO_H
#define NAO_H
#include "Classifier.h"
#include "ObjectExtractor.h"
#include "Object.h"
#include "ClassifierState.h"
#include "Classifier.h"

class Nao
{
    public:
        Nao();
        Nao(Classifier* classifier):classifier(classifier){};
        virtual ~Nao();
        void init();
        void lookForObject();
        void showObject();
        void trainClassifier();
        void loadClassifier();
        bool classifyObject();
        unsigned int testClassifier();
        void showClassifierState();
    protected:
    private:
        ObjectExtractor objectExtractor;
        Classifier* classifier;
        Object lastDetectedObject;
};

#endif // NAO_H
