#include "test.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
void mainAllessandro(Mat& src){
    resize(src, src, Size_<int>(src.cols/2, src.rows/2));
    /// Convert image to gray and blur it

    Mat channel[3];
    // The actual splitting.
    split(src, channel);


    channel[1]=Mat::zeros(src.rows, src.cols, CV_8UC1);//Set green channel to 0
    channel[0]=Mat::zeros(src.rows, src.cols, CV_8UC1);//Set green channel to 0
    //Merging red and blue channels
    merge(channel,3,src);

    cvtColor( src, src_gray, CV_BGR2GRAY );
    medianBlur( src_gray, src_gray, 9 );
    equalizeHist(src_gray, src_gray);
    /// Create Window
    string source_window = "Source";
    namedWindow( source_window, CV_WINDOW_AUTOSIZE );
    imshow( source_window, src_gray );

    createTrackbar( " Threshold:", "Source", &thresh, max_thresh, thresh_callback );
    createTrackbar( " Erode:", "Source", &thresh, max_thresh, erode_callback );

    thresh_callback( 0, 0 );


    threshold( src_gray, output, 245, 255, THRESH_BINARY );
    erode(output, output, Mat());
    dilate(output, output, Mat());

    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    dilate(output, output, Mat());
    imshow("Threshould", output);

    Mat result;
    //cvtColor( src, result, CV_BGR2GRAY );

    result =src_gray.mul(output/255);
    imshow("result", result);


    waitKey(0);
}


void showImageStop(Mat& img,string name){
    imshow(name, img);
    waitKey(0);
}

void erode_callback(int, void* ){
    cout << "erode" << endl;
    dilate(output, output, Mat());
    imshow("Threshould", output);
}


/** @function thresh_callback */
void thresh_callback(int, void* )
{

    /// Detect edges using Threshold
   // medianBlur(src_gray, src_gray,3);
    threshold( src_gray, output, thresh, 255, THRESH_BINARY );
    cout << thresh << endl;
    erode(output, output, Mat());
    dilate(output, output, Mat());
    imshow("Threshould", output);
}
