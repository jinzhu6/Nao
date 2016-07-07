/*
 * main.cpp
 *
 *  Created on: 29 juin 2016
 *      Author: Emmanuel
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "Classifier.h"
#include "test.h"

#include <iostream>
using namespace cv;
using namespace std;

/** @function main */
int main( int argc, char** argv )
{
    Mat src;
    //Mat dst;
	if(argc < 2){
		puts("too few arguments");
		return 0;
	}
	else{
		printf("%s\n",argv[1]);
	}
    /// Load source image and convert it to gray

    src = imread( argv[1], 1 );
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
    Classifier classifier;


    return(0);
}

