#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgcodecs.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace cv;

struct FkOpencv{
    string winname;
    Mat src1;
    Mat src2;
    FkOpencv(string winname_, Mat& src1_,Mat& src2_):
        winname(winname_),src1(src1_),src2(src2_){}
};

void on_blendingAdjustment(int bar_val, void* userdata)
{   
    FkOpencv fk = *(FkOpencv*)(userdata);
    Mat dst;
    float blending_beta = ( 1.0 - (float)bar_val/100 );
    addWeighted( fk.src1, (float)bar_val/100, fk.src2, blending_beta, 0.0, dst);
    imshow( fk.winname, dst );
    cout << "finished " << (float)bar_val/100 << endl;
}

void blending(){
    string winname = "Blending";
    Mat src1;
    Mat src2;
    src1 = imread( "../left.png" );
    src2 = imread( "../right.png" );
    namedWindow(winname, 1);
    imshow(winname,src2);
    int value = 0;
    FkOpencv fk(winname,src1,src2);
    createTrackbar("alpha值 ", winname, &value, 100, on_blendingAdjustment, &fk);
    waitKey();
    destroyAllWindows();
}

int main(){
    blending();
    return 0;
}