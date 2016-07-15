#include "test.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

Mat outputMatrix;
Mat src_gray;
RNG rng(12345);

int thresh = 100;
int max_thresh = 255;


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


    threshold( src_gray, outputMatrix, 245, 255, THRESH_BINARY );
    erode(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());

    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    imshow("Threshould", outputMatrix);

    Mat result;
    //cvtColor( src, result, CV_BGR2GRAY );

    result =src_gray.mul(outputMatrix/255);
    imshow("result", result);


    waitKey(0);
}


void showImageStop(Mat& img,string name){
    imshow(name, img);
    waitKey(0);
}

void erode_callback(int, void* ){
    cout << "erode" << endl;
    dilate(outputMatrix, outputMatrix, Mat());
    imshow("Threshould", outputMatrix);
}


/** @function thresh_callback */
void thresh_callback(int, void* )
{

    /// Detect edges using Threshold
   // medianBlur(src_gray, src_gray,3);
    threshold( src_gray, outputMatrix, thresh, 255, THRESH_BINARY );
    cout << thresh << endl;
    erode(outputMatrix, outputMatrix, Mat());
    dilate(outputMatrix, outputMatrix, Mat());
    imshow("Threshould", outputMatrix);
}

void contrast_enhance(Mat& src, Mat& dst){
    int x;
    int y;
    int c;
    for(y = 0; y < src.rows; y++){
        for(x = 0; x < src.cols; x++){
            for(c = 0; c < 3; c++){
                dst.at<Vec3b>(y,x)[c] = src.at<Vec3b>(y,x)[c]*ALPHA;
            }
        }
    }
}


void apply_mask(Mat& src, Mat& dst, Mat& mask){
    int x;
    int y;
    int c;
    for(y = 0; y < src.rows; y++){
        for(x = 0; x < src.cols; x++){
            for(c = 0; c < 3; c++){

                if(mask.at<Vec3b>(y,x)[c] == 1){
                    cout << mask.at<Vec3b>(y,x)[c]+0 << ",";
                    dst.at<Vec3b>(y,x)[c] = src.at<Vec3b>(y,x)[c];
                }
                else
                    dst.at<Vec3b>(y,x)[c] = 0;
            }
        }
    }
}
void mainManu(Mat& src){
Mat channel[3];
    // The actual splitting.
    split(src, channel);
    Mat dst = Mat::zeros(src.rows/4,src.cols/4,src.type());
    resize(src, dst, dst.size(), 0, 0, INTER_NEAREST );
    src = dst;
    cvtColor(dst,dst,CV_BGR2GRAY);
    Mat gray = dst;
    imshow("gray", gray);
    //equalizeHist(dst,dst);
    //normalize(dst, dst, 0, 1., NORM_MINMAX);
    distanceTransform(dst, dst, CV_DIST_L1,3);
    imshow("dist transform", dst);
    //
    threshold( dst, dst, 20, 255, THRESH_BINARY_INV );
    Mat mask = dst;
    //cout << mask.depth() << endl;
    //bitwise_and(src,dst,mask);
    imshow("img before", src);
    showImageStop(dst,"find apples");
}
