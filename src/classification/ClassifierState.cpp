#include "ClassifierState.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
string intToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}
ClassifierState::ClassifierState()
{
    //ctor
}

ClassifierState::~ClassifierState()
{
    //dtor
}

void ClassifierState::storeValues()
{
    ofstream myfile;
    myfile.open (storingPath);


    for(auto val = valueList.cbegin(); val != valueList.cend(); val++)
    {
        myfile << intToString(*val);
        myfile << " ";
    }
    myfile << "\0";
    myfile.close();
};

void ClassifierState::loadValues()
{
    string line;
    ifstream myfile (storingPath);
    string::size_type sz;
    if (myfile.is_open())
    {
        getline(myfile,line);
        int i = 0;
        string tmp = "";
        int value;


        while(line[i] != '\0'){
            if(line[i] == ' '){
                const char* txtValue = tmp.c_str();
                sscanf ( txtValue, "%d", &value );
                this->valueList.push_back(value);
                tmp = "";
            }
            else{
                tmp.push_back(line[i]);
            }
            i++;
        }
    }
};

void ClassifierState::train(const string& path)
{
    for(auto feature = featureList.cbegin(); feature != featureList.cend(); feature++){
        //valueList.push_back(feature->)
    }

};

unsigned int ClassifierState::test()
{
    return 0;
};
