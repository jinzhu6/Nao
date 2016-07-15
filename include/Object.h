#ifndef OBJECT_H
#define OBJECT_H
#include "Feature.h"
#include <opencv2/core.hpp>

using namespace cv;
class Object
{
    public:
        Object(Mat& img, const string name);
        virtual ~Object();
        unsigned int extract_feature(Feature& feature);
        void show();
        void showComputed();
        void resizeObject(unsigned short divisor);
        void preTreat();
        void noPreTreat();
        void saveResult();
    protected:

    private:
        Mat& img;
        Mat computedMatrix;
        const string name;
};

#endif // OBJECT_H
