#ifndef ANGULARSECONDMOMENT_H
#define ANGULARSECONDMOMENT_H

#include <Feature.h>


class AngularSecondMoment : public Feature
{
    public:
        AngularSecondMoment();
        virtual ~AngularSecondMoment();
        float extractIn(Mat& img);

    protected:
    private:
};

#endif // ANGULARSECONDMOMENT_H
