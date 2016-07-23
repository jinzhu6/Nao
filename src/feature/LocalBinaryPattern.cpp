#include "LocalBinaryPattern.h"
#include <opencv2/highgui.hpp>



LocalBinaryPattern::LocalBinaryPattern()
{
    //ctor
}


LocalBinaryPattern::~LocalBinaryPattern()
{
    //dtor
}

template <typename _Tp>
void LocalBinaryPattern::compute(Mat& src)
{
    resultingImage = Mat::zeros(src.rows-2, src.cols-2, CV_8UC1);
    for(int i=1; i<src.rows-1; i++)
    {
        for(int j=1; j<src.cols-1; j++)
        {
            _Tp center = src.at<_Tp>(i,j);
            unsigned char code = 0;
            code |= (src.at<_Tp>(i-1,j-1) > center) << 7;
            code |= (src.at<_Tp>(i-1,j) > center) << 6;
            code |= (src.at<_Tp>(i-1,j+1) > center) << 5;
            code |= (src.at<_Tp>(i,j+1) > center) << 4;
            code |= (src.at<_Tp>(i+1,j+1) > center) << 3;
            code |= (src.at<_Tp>(i+1,j) > center) << 2;
            code |= (src.at<_Tp>(i+1,j-1) > center) << 1;
            code |= (src.at<_Tp>(i,j-1) > center) << 0;
            resultingImage.at<unsigned char>(i-1,j-1) = code;
        }
    }
}

 float LocalBinaryPattern::extractIn(Mat& img){
    compute<uchar>(img);
    cv::imshow("image computed", resultingImage);
    return 0;
 }
