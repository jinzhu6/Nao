#ifndef FIRSTSPLITSTATE_H
#define FIRSTSPLITSTATE_H

#include <ClassifierState.h>


class FirstSplitState : public ClassifierState
{
    public:
        FirstSplitState(vector<Feature*> featureList);
        virtual ~FirstSplitState();

    protected:
    private:
};

#endif // FIRSTSPLITSTATE_H
