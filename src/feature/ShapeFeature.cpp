#include "ShapeFeature.hpp"
#include <opencv2/highgui.hpp>
#include "opencv2/imgproc.hpp"

#include <iostream>



ShapeFeature::ShapeFeature()
{
    normalisationDivider = 1;
}


ShapeFeature::~ShapeFeature()
{
    //dtor
}

template <typename _Tp>
void ShapeFeature::compute(Mat& src)
{
    resultingImage = src;

    Mat channel[3];
    // The actual splitting.
    split(resultingImage, channel);

    channel[1].setTo(Scalar(0));

    Mat br;
    merge(channel,3,br);

    channel[0].setTo(Scalar(0));
    Mat r;
    merge(channel,3,r);

    cvtColor(r, r, CV_BGR2GRAY);
    medianBlur(r, r, 9 );
    equalizeHist(r, r);

    threshold(r, r, 120, 255, THRESH_BINARY);

    erode(r, r, Mat());
    dilate(r, r, Mat());




    vector< vector <Point> > contours; // Vector for storing contour
    vector< Vec4i > hierarchy;
    int largest_contour_index=0;
    int largest_area=0;
    findContours( r.clone(), contours, hierarchy,RETR_EXTERNAL, CHAIN_APPROX_SIMPLE ); // Find the contours in the image
    for( int i = 0; i< contours.size(); i++ ){
        double a=contourArea( contours[i],false);  //  Find the area of contour
        if(a>largest_area){
            largest_area=a;
            largest_contour_index=i;                //Store the index of largest contour
        }
    }

    Mat pointsf;
    Mat(contours[largest_contour_index]).convertTo(pointsf, CV_32F);
    RotatedRect boxE = fitEllipse(pointsf);
    if(boxE.size.width<boxE.size.height)
        value = (float)boxE.size.width/boxE.size.height;
    else
        value = (float)boxE.size.height/boxE.size.width;

}

float ShapeFeature::extractIn(Mat& img){
    compute<uchar>(img);
    //cv::imshow("image computed", resultingImage);
    return value;
}
