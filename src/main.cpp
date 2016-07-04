/*
 * main.cpp
 *
 *  Created on: 29 juin 2016
 *      Author: Emmanuel
 */
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Classifier.h"

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

    Classifier classifier;


    return(0);
}

