#include <iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#define dg "E:/data/courses/dg/"
#define dgdata dg"static/"
int main() {
   Mat img = imread(dgdata"9_11.png");
   imshow("apple", img);
   waitKey(0);
   destroyAllWindows();
  cout<<"hello";
  return 0;
}