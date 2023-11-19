#include <iostream>
#include<opencv2/opencv.hpp>
#include "dg.h"
using namespace std;
using namespace cv;
#define dg "E:/data/courses/dg/"
#define dgdata dg"static/"
Mat img = imread(dgdata"9.11.png");

int main() {
  // Mat img1 = testimage(img);
  Mat dftimg = dftImage(img);
  imshow("monalisa", img);
  imshow("dftimg", dftimg);
  // imshow("img1", img1);
  waitKey(0);
  destroyAllWindows();
  cout << "hello";

  return 0;
}