//
// Created by f on 2023/11/19.
//

#ifndef DG_H
#define DG_H
#include <iostream>
#include <opencv2/opencv.hpp>
#include"shared_lib.h"
SHARED_LIB_API cv::Mat dftImage(cv::Mat img);
SHARED_LIB_API cv::Mat testimage(cv::Mat img);
#endif //DG_H