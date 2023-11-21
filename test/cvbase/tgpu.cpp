//
// Created by f on 2023/11/19.
//
#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
  cout<<cuda::getCudaEnabledDeviceCount()<<endl;
  return 0;
}
