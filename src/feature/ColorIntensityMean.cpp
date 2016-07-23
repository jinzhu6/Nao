#include "ColorIntensityMean.h"
#include <iostream>

using namespace std;
ColorIntensityMean::ColorIntensityMean()
{
    normalisationDivider = 255;
}

ColorIntensityMean::~ColorIntensityMean()
{
}


template <typename _Tp, typename _Ttab>
void ColorIntensityMean::compute(Mat& src)
{
    _Ttab pixelMeanTable;
    int pixelMean = 0;
    int rowMean = 0;

    for(int i=1; i<src.rows-1; i++)
    {
        rowMean = 0;
        for(int j=1; j<src.cols-1; j++)
        {
            pixelMean = 0;
            for(int c = 0; c < 3; c++)
            {
                pixelMean += (src.at<_Ttab>(i,j))[c];
            }

            pixelMean /= 3;
            rowMean += pixelMean;

        }
        rowMean /= src.cols;
        value += rowMean;

    }

    value /= src.rows;
    normalise();
    cout << "value normalised : " << value << endl;
}

int ColorIntensityMean::extractIn(Mat& img)
{
    compute<uint32_t,Vec3b>(img);

    //cv::imshow("image computed", resultingImage);

    return value;
}



