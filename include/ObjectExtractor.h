#ifndef OBJECTEXTRACTOR_H
#define OBJECTEXTRACTOR_H

#include "Object.h"

class ObjectExtractor
{
    public:
        ObjectExtractor();
        virtual ~ObjectExtractor();
    protected:
    private:
        Object currentDetectedObject;
};

#endif // OBJECTEXTRACTOR_H
