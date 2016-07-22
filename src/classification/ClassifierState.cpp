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
    string currentPath = path;
    currentPath.append("values/");
    currentPath.append("positive.txt");
    myfile.open (currentPath, ios::out);

    if (!myfile.is_open())
    {
        cout << "unable to open the file during store values\nPath : " << currentPath << endl;
        return;
    }
    cout << "storing values in " << currentPath << endl;
    for(auto valList = positiveValueList.cbegin(); valList != positiveValueList.cend(); valList++)
    {
        for(auto val = valList->cbegin(); val != valList->cend(); val++)
        {
            myfile << intToString(*val);
            myfile << " ";
        }
        myfile << "\n";
    }
    myfile.close();
    currentPath = path;
    currentPath.append("values/");
    currentPath.append("negative.txt");
    myfile.open (currentPath, ios::out);

    if (!myfile.is_open())
    {
        cout << "unable to open the file during store values\nPath : " << currentPath << endl;
        return;
    }
    cout << "storing values in " << currentPath << endl;
    for(auto valList = negativeValueList.cbegin(); valList != negativeValueList.cend(); valList++)
    {
        for(auto val = valList->cbegin(); val != valList->cend(); val++)
        {
            myfile << intToString(*val);
            myfile << " ";
        }
        myfile << "\n";
    }

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
    string currentPath = path;
    currentPath.append("values/");
    currentPath.append("positive.txt");
    ifstream myfile (currentPath);
    if (myfile.is_open())
    {
        int i = 0;
        string tmp = "";
        while(getline(myfile,line))
        {
            vector<unsigned int> featureValues;
            while(line[i] != '\0')
            {
                if(line[i] == ' ')
                {
                    featureValues.push_back(getInt(tmp));
                    tmp = "";
                }
                else
                {
                    tmp.push_back(line[i]);
                }
                i++;
            }
            this->positiveValueList.push_back(featureValues);
        }
    }

    currentPath = path;
    currentPath.append("values/");
    currentPath.append("negative.txt");
    myfile.close();
    myfile.open(currentPath);
    if (myfile.is_open())
    {
        int i = 0;
        string tmp = "";
        while(getline(myfile,line))
        {
            vector<unsigned int> featureValues;
            while(line[i] != '\0')
            {
                if(line[i] == ' ')
                {
                    featureValues.push_back(getInt(tmp));
                    tmp = "";
                }
                else
                {
                    tmp.push_back(line[i]);
                }
                i++;
            }
            this->negativeValueList.push_back(featureValues);
        }
    }
};

void ClassifierState::train(const string& type)
{
    vector< vector< unsigned int> >* valueList;
    if(type == "positive")
    {
        valueList = &positiveValueList;
    }
    else
    {
        valueList = &negativeValueList;
    }
    string line;
    string trainPath = path;
    trainPath.append("train/");
    trainPath.append(type);

    string numberPath = trainPath;
    numberPath.append("/number.txt");
    string currentImagePath = trainPath;
    cout << "Number of images in the folder " << trainPath << " :\n";
    ifstream myfile (numberPath);
    int numberOfImages = 0;
    Mat currentImage;
    vector<Mat> images;
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
                images.push_back(currentImage);
            }
            else
            {
                cout << "fail when opening the file :\n" << currentImagePath << endl;
            }
            currentImagePath = trainPath;
        }
    }
    else
    {
        cout << "fail to open the file containing the number of images" << endl;
    }
    for(auto feature = featureList.begin(); feature != featureList.end(); feature++)
    {
        vector<unsigned int> valList;

        for(auto image = images.begin(); image != images.end(); image++)
        {
            valList.push_back((*feature)->extractIn(*image));
        }
        valueList->push_back(valList);
    }
    cout << "computing means:" << endl;
    computeMeans();
};


unsigned int ClassifierState::test()
{
    return 0;
};


void ClassifierState::showValues()
{
    cout << "positive values : " << endl;

    for(auto values = positiveValueList.cbegin(); values != positiveValueList.cend(); values++)
    {
        cout << "feature :" << endl;
        for(auto value = values->cbegin(); value != values->cend(); value++)
        {
            cout << *value+0 << " ";
        }
        cout << endl;
    }

    cout << endl << "negative values : " << endl;
    for(auto values = negativeValueList.cbegin(); values != negativeValueList.cend(); values++)
    {
        cout << "feature :" << endl;
        for(auto value = values->cbegin(); value != values->cend(); value++)
        {
            cout << *value+0 << " ";
        }
        cout << endl;
    }
}


unsigned int getMean(const vector<unsigned int>* listOfValues)
{
    unsigned int mean = 0;
    for(auto val = listOfValues->cbegin(); val != listOfValues->cend(); val++)
    {
        mean += *val;
    }
    mean /= listOfValues->size();
    return mean;
}

void ClassifierState::computeMeans()
{
    cout << "computation of the means" << endl;
    for(auto values = positiveValueList.cbegin(); values != positiveValueList.cend(); values++)
    {
        positiveMeans.push_back(getMean(&(*values)));
        cout << getMean(&(*values)) << " ";
    }
    cout << endl;
    for(auto values = negativeValueList.cbegin(); values != negativeValueList.cend(); values++)
    {
        negativeMeans.push_back(getMean(&(*values)));
    }
}

void ClassifierState::showMeans()
{

    cout << "Positive features :" << endl;
    for(auto val = positiveMeans.cbegin(); val != positiveMeans.cend(); val++)
    {
        cout << *val << " ";
    }
    cout << endl << "Negative features :" << endl;
    for(auto val = negativeMeans.cbegin(); val != negativeMeans.cend(); val++)
    {
        cout << *val << " ";
    }
    cout << endl;
}



