#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;
int main()
{

    //Вывод обычной картинки
    Mat bugs = imread("picha.jpg");
    imshow("Original image", bugs);
    waitKey(0);
    destroyAllWindows();

    //черно-белое изображение
    Mat cb_bugs;
    cvtColor(bugs,cb_bugs,COLOR_BGR2GRAY);
    imshow("bw image", cb_bugs);
    waitKey(0);
    destroyAllWindows();

    //Размытие
    Mat raz_bugs;
    GaussianBlur(bugs,raz_bugs,{21,21},20);
    imshow("Razmitoe image", raz_bugs);
    waitKey(0);
    destroyAllWindows();

    //Lab_color_space
    Mat lab_bugs;
    cvtColor(bugs,lab_bugs,COLOR_Lab2LBGR);
    imshow("lab image", lab_bugs);
    waitKey(0);
    destroyAllWindows();

    //HSV
    Mat hsv_bugs;
    cvtColor(bugs,hsv_bugs,COLOR_HSV2BGR_FULL);
    imshow("HSV image", hsv_bugs);
    waitKey(0);
    destroyAllWindows();

    //Canny
    Mat edge,draw;
    Canny(cb_bugs,edge,50,130);
    edge.convertTo(draw,CV_8U);
    imshow("Canny", draw);
    waitKey(0);
    destroyAllWindows();
    return 0;
}
