#ifndef STARTSTATE_H
#define STARTSTATE_H

#include <StateClassifier.h>


class StartState : public StateClassifier
{
    public:
        StartState();
        virtual ~StartState();
        void handle();
    protected:
    private:
};

#endif // STARTSTATE_H
