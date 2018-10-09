#include"../header/header.h"
using namespace std;
using namespace cv;


Mat sobel1(Mat src,Mat sobel,Mat grad_x,Mat grad_y,Mat abs_grad_x,Mat abs_grad_y){

    cvtColor(src,src,CV_BGR2GRAY);
    GaussianBlur(src, src, Size(3,3), 0, 0);
    Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
    convertScaleAbs(grad_x, abs_grad_x);  //Âà¦¨CV_8U
    Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT );
    convertScaleAbs(grad_y, abs_grad_y);

    Mat dst1;
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, dst1);
    //threshold(dst1, sobel, 80, 255, THRESH_BINARY|THRESH_OTSU);

    return dst1;
}
