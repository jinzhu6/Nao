#include "ClassifierState.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "opencv2/highgui.hpp"

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
    myfile.open (storingPath, ios::out);

    if (!myfile.is_open())
    {
        cout << "unable to open the file during store values\nPath : " << storingPath << endl;
        return;
    }
    cout << "storing values in " << storingPath << endl;
    for(auto val = valueList.cbegin(); val != valueList.cend(); val++)
    {
        myfile << intToString(*val);
        myfile << " ";
    }
    myfile << "\0";
    myfile.close();
};

int getInt(string s)
{
    int value;
    const char* txtValue = s.c_str();
    sscanf ( txtValue, "%d", &value );
    return value;
}

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
        while(line[i] != '\0')
        {
            if(line[i] == ' ')
            {
                this->valueList.push_back(getInt(tmp));
                tmp = "";
            }
            else
            {
                tmp.push_back(line[i]);
            }
            i++;
        }
    }
};

void ClassifierState::train(const string& path)
{
    string line;
    string numberPath = path;
    numberPath.append("/number.txt");
    string currentImagePath = path;
    cout << "Number of images in the folder " << path << " :\n";
    ifstream myfile (numberPath);
    int numberOfImages = 0;
    Mat currentImage;
    if (myfile.is_open())
    {
        getline(myfile,line);
        numberOfImages = getInt(line);
        cout << numberOfImages+0 << endl;
        for(int i = 0; i < numberOfImages; i++)
        {
            currentImagePath.append("/image");
            currentImagePath.append(intToString(i));
            currentImagePath.append(".jpg");
            currentImage = imread(currentImagePath);
            if(currentImage.data)
            {
                for(auto feature = featureList.begin(); feature != featureList.end(); feature++)
                {
                    this->valueList.push_back((*feature)->extractIn(currentImage));
                }
            }else{
                cout << "fail when opening the file :\n" << currentImagePath << endl;
            }
            currentImagePath = path;
        }
    }
    else
    {
        cout << "fail to open the file containing the number of images" << endl;
    }
};

unsigned int ClassifierState::test()
{
    return 0;
};
