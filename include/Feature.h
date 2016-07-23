#ifndef FEATURE_H
#define FEATURE_H
#include <opencv2/core.hpp>


using namespace cv;
class Feature
{
    public:
        Feature(){};
        virtual ~Feature(){};
        virtual float extractIn(Mat& img) = 0;

    protected:
        Mat resultingImage;
        float value = 0;
        int normalisationDivider;
        virtual float normalise();


    private:
        template <typename _Tp>
        void compute(Mat& src);
};

#endif // FEATURE_H
