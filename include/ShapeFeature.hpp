//
//  ShapeFeature.hpp
//  sayhelloworld
//
//  Created by Alessandro Imbrenda on 23/07/16.
//
//

#ifndef ShapeFeature_hpp
#define ShapeFeature_hpp

#include "Feature.h"

class ShapeFeature : public Feature
{
public:
    ShapeFeature();
    virtual ~ShapeFeature();
    float extractIn(Mat& img);
protected:
private:
    template <typename _Tp>
    void compute(Mat& src);
};



#endif /* ShapeFeature_hpp */
