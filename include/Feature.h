#ifndef FEATURE_H
#define FEATURE_H
#include <opencv2/core.hpp>


using namespace cv;
class Feature
{
    public:
        Feature();
        virtual ~Feature();
        virtual int extractIn(Mat& img);

    protected:
        Mat resultingImage;
        int value = 0;

    private:
        template <typename _Tp>
        void compute(Mat& src);
};

#endif // FEATURE_H
