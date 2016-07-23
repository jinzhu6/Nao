#include "Feature.h"
#include "iostream"

using namespace std;
float Feature::normalise(){
    return value /=normalisationDivider;

}
