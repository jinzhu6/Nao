#ifndef NAO_H
#define NAO_H
#include "Classifier.h"
#include "ObjectExtractor.h"
#include "Object.h"
#include "ClassifierState.h"
#include "Classifier.h"
#include "ColorIntensityMean.h"
#include "GlassCupSplitState.hpp"
#include "ShapeFeature.hpp"
#include "FirstSplitState.h"

class Nao
{
    public:
        Nao();
        virtual ~Nao();
        void init();
        void lookForObject();
        void showObject();
        void trainClassifier();
        void loadClassifier();
        string classifyObject();
        unsigned int testClassifier();
        void showClassifierState();
    protected:
    private:
        Classifier classifier;
        Object lastDetectedObject;

        FirstSplitState fss;
        GlassCupSplitState gcs;

        vector<Feature*> firstStateFeatList;
        vector<Feature*> glassCupSplitList;

        ColorIntensityMean colorIntensityMean;
        ShapeFeature shapeFeature;


};

#endif // NAO_H
