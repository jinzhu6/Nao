#ifndef LOCALBINARYPATTERN_H
#define LOCALBINARYPATTERN_H
#include "Feature.h"

class LocalBinaryPattern : public Feature
{
    public:
        LocalBinaryPattern();
        virtual ~LocalBinaryPattern();
        int extractIn(Mat& img);
    protected:
    private:
        template <typename _Tp>
        void compute(Mat& src);
};



#endif // LOCALBINARYPATTERN_H
