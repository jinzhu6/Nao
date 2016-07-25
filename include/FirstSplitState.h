#ifndef FIRSTSPLITSTATE_H
#define FIRSTSPLITSTATE_H

#include <ClassifierState.h>


class FirstSplitState : public ClassifierState
{
    public:
        FirstSplitState(){};
        FirstSplitState(vector<Feature*>* featureList
                        ,ClassifierState* succesivePositiveState
                        ,ClassifierState* successiveNegativeState);
        virtual ~FirstSplitState();

    protected:
    private:
};

#endif // FIRSTSPLITSTATE_H
