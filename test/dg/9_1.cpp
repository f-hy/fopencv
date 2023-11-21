#include <iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/cudaimgproc.hpp>
#include "dg.h"
using namespace std;
using namespace cv;
// #define dg "E:/data/courses/dg/"
// #define dgdata dg"static/"
// #define imgpath dgdata"9.11.png"

int main() {
  const String& s ="E:/apple.jpg";
  Mat img = imread(s);
  if(img.empty()) {
    cout<<"IMG is empty"<<endl;
    img = Mat(300, 300, CV_8UC3, Scalar(255, 0, 255));
  }
  // cout<<imgpath<<endl;
  cout<<img.size<<endl;
  // Mat img1 = testimage(img);
  // Mat dftimg = dftImage(img);
  imshow("monalisa", img);
  imwrite("E:/a.png", img);
  // imshow("dftimg", dftimg);
  // imshow("img1", img1);
  waitKey(0);
  destroyAllWindows();
  cout << "hello";

  return 0;
}