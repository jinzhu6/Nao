#include "ClassifierState.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "opencv2/highgui.hpp"

using namespace std;
string floatToString (float a)
{
    ostringstream temp;
    temp<<a+0.0;
    return temp.str();
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
            myfile << floatToString(*val);
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
            myfile << floatToString(*val);
            myfile << " ";
        }
        myfile << "\n";
    }

    myfile.close();
};

float getFloat(string s)
{
    float value;
    const char* txtValue = s.c_str();
    sscanf ( txtValue, "%f", &value );
    return value;
}

string ClassifierState::classify(Object &object)
{
    if(finalState)
    {
        return positiveClassName;
    }
    vector<float> objectValues;
    for(auto feature = featureList->begin(); feature != featureList->end(); feature++)
    {
        objectValues.push_back((*feature)->extractIn(object.img));
    }
    float distanceToPositiveMean = 0;
    int i = 0;
    for(auto val = objectValues.begin(); val != objectValues.end(); val++)
    {
        distanceToPositiveMean += abs(positiveMeans[i] - *val);
        i++;
    }
    distanceToPositiveMean /= featureList->size();
    cout << "distance to positive mean : " << distanceToPositiveMean << endl;
    float distanceToNegativeMean = 0;
    i = 0;
    for(auto val = objectValues.begin(); val != objectValues.end(); val++)
    {
        distanceToNegativeMean += abs(negativeMeans[i] - *val);
        i++;
    }
    distanceToNegativeMean /= featureList->size();
    cout << "distance to negative mean : " << distanceToNegativeMean << endl;


    if(distanceToNegativeMean > distanceToPositiveMean)
    {
        if(finalState)
        {
            return positiveClassName;
        }
        else
        {
            return succesivePositiveState->classify(object);
        }
    }
    else
    {
        if(finalState)
        {
            return negativeClasseName;
        }
        else
        {
            return successiveNegativeState->classify(object);
        }
    }
}

void ClassifierState::compareToMean(vector<float>& valueList)
{


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
            vector<float> featureValues;
            while(line[i] != '\0')
            {
                if(line[i] == ' ')
                {
                    featureValues.push_back(getFloat(tmp));
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
            vector<float> featureValues;
            while(line[i] != '\0')
            {
                if(line[i] == ' ')
                {
                    featureValues.push_back(getFloat(tmp));
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
    computeMeans();
};

void ClassifierState::train(const string& type)
{
    vector< vector< float> >* valueList;
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
        numberOfImages = getFloat(line);
        cout << numberOfImages+0 << endl;
        for(int i = 0; i < numberOfImages; i++)
        {
            currentImagePath.append("/image");
            currentImagePath.append(floatToString(i));
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
    for(auto feature = featureList->begin(); feature != featureList->end(); feature++)
    {
        vector<float> valList;

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
            cout << *value << " ";
        }
        cout << endl;
    }

    cout << endl << "negative values : " << endl;
    for(auto values = negativeValueList.cbegin(); values != negativeValueList.cend(); values++)
    {
        cout << "feature :" << endl;
        for(auto value = values->cbegin(); value != values->cend(); value++)
        {
            cout << *value << " ";
        }
        cout << endl;
    }
}


float getMean(const vector<float>* listOfValues)
{
    float mean = 0;
    for(auto val = listOfValues->cbegin(); val != listOfValues->cend(); val++)
    {
        mean += *val;
    }
    mean /= listOfValues->size();
    return mean;
}

void ClassifierState::computeMeans()
{
    positiveMeans.clear();
    negativeMeans.clear();
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



