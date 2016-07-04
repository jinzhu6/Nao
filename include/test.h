#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <opencv2/core.hpp>

using namespace cv;
using namespace std;

Mat src_gray;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);
Mat output;

/// Function header
void thresh_callback(int, void* );
void erode_callback(int, void* );

void mainAllessandro(Mat& src);
void showImageStop(Mat& img,string name);
void erode_callback(int, void* );
void thresh_callback(int, void* );
#endif // TEST_H_INCLUDED
