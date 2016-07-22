#ifndef OBJECT_H
#define OBJECT_H
#include "Feature.h"
#include <opencv2/core.hpp>

using namespace cv;
class Object
{
    public:
        Object(){img = Mat::zeros(0,0,0);};
        Object(Mat& img, const string name);
        virtual ~Object();
        unsigned int extract_feature(Feature& feature);
        void show();
        void showComputed();
        void resizeObject(unsigned short divisor);
        void preTreat();
        void noPreTreat();
        void saveResult(Mat& img);
        Object operator=(const Object o);
        Mat img;
    protected:

    private:

        Mat computedMatrix;
        string name;
};

#endif // OBJECT_H
