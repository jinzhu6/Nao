#ifndef COLORINTENSITYMEAN_H
#define COLORINTENSITYMEAN_H

#include <Feature.h>


class ColorIntensityMean : public Feature
{
    public:
        ColorIntensityMean();
        virtual ~ColorIntensityMean();
        virtual float extractIn(Mat& img);

    protected:

    private:
        template <typename _Tp, typename _Ttab>
        void compute(Mat& src);
};

#endif // COLORINTENSITYMEAN_H
