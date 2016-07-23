#include "Feature.h"
#include "iostream"

using namespace std;
unsigned int Feature::normalise(){
    cout << "value : " << value << endl << "Divider : " << normalisationDivider << endl;
    return value /=normalisationDivider;

}
