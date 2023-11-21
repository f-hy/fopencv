#include <iostream>
#include<opencv2/opencv.hpp>
#include "dg.h"
using namespace std;
using namespace cv;
#define dg "E:/data/courses/dg/"
#define dgdata dg"static/"
#define imgpath dgdata"9.11.png"
//用cv::dft对输入图像（可以只考虑单通道图像）进行傅里叶变换，显示其功率谱，并测试非移中和移中的情况。

int main() {
  Mat img  = imread(imgpath);
  // Mat img1 = testimage(img);
  Mat dftimg = dftImage(img);
  imshow("monalisa", img);
  imshow("dftimg", dftimg);
  // imshow("img1", img1);
  waitKey(0);
  destroyAllWindows();
  return 0;
}