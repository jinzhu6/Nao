//
//  GlassCupSplitState.hpp
//  sayhelloworld
//
//  Created by Alessandro Imbrenda on 23/07/16.
//
//

#ifndef GlassCupSplitState_hpp
#define GlassCupSplitState_hpp

#include "ClassifierState.h"


class GlassCupSplitState : public ClassifierState
{
public:
    GlassCupSplitState(){};
    GlassCupSplitState(vector<Feature*>* featureList);
    virtual ~GlassCupSplitState();

protected:
private:
};

#endif /* GlassCupSplitState_hpp */
