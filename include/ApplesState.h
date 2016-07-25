#ifndef APPLESSTATE_H
#define APPLESSTATE_H

#include <ClassifierState.h>


class ApplesState : public ClassifierState
{
    public:
        ApplesState(){};
        ApplesState(vector<Feature*>* featureList,
                         ClassifierState* succesivePositiveState,
                         ClassifierState* successiveNegativeState);
        virtual ~ApplesState();
    protected:
    private:
};

#endif // APPLESSTATE_H
