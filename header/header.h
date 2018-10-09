#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define _SCL_SECURE_NO_WARNINGS
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>
#include <cstdio>
#include <ratio>
using namespace cv;
int file();
Mat sobel1(Mat src,Mat sobel,Mat grad_x,Mat grad_y,Mat abs_grad_x,Mat abs_grad_y);



#endif // HEADER_H_INCLUDED
