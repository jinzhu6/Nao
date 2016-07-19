#ifndef FIRSTSPLITSTATE_H
#define FIRSTSPLITSTATE_H

#include <ClassifierState.h>


class FirstSplitState : public ClassifierState
{
    public:
        FirstSplitState();
        virtual ~FirstSplitState();
        void storeValues();
        void loadValues();
        void train();
        unsigned int test();
    protected:
    private:
};

#endif // FIRSTSPLITSTATE_H
