#include"dg.h"
using namespace cv;
cv::Mat testimage(cv::Mat img) {
  return img;
}
Mat dftImage(Mat img) {
  if (img.channels() != 1) {
    cvtColor(img, img, COLOR_RGB2GRAY); //单通道灰度图
  }
  Mat padded;
  int M = getOptimalDFTSize(img.rows); //将输入图像延扩到最佳的尺寸
  int N = getOptimalDFTSize(img.cols);
  copyMakeBorder(img, padded, 0, M - img.rows, 0, N - img.cols, BORDER_CONSTANT, Scalar::all(0));

  Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)}; //为傅立叶变换的结果(实部和虚部)分配存储空间
  Mat complexImg;
  merge(planes, 2, complexImg); //为延扩后的图像增添一个初始化为0的通道
  dft(complexImg, complexImg); //进行离散傅立叶变换

  // compute log(1 + sqrt(Re(DFT(img))**2 + Im(DFT(img))**2))  将实数和复数的值转换为幅度值
  split(complexImg, planes);
  magnitude(planes[0], planes[1], planes[0]);
  Mat mag = planes[0];
  mag += Scalar::all(1); //转换为对数尺度
  log(mag, mag);
  // crop the spectrum, if it has an odd number of rows or columns
  mag = mag(Rect(0, 0, mag.cols, mag.rows)); //如果有奇数行或列，则对频谱进行裁剪

  Mat mag2 = mag.clone();
  normalize(mag, mag, 0, 1, NORM_MINMAX); //归一化处理，用0-1之间的浮点数将矩阵变换为可视的图像格式
  mag.convertTo(mag, CV_8UC1, 255, 0);

  int cx = mag.cols / 2;
  int cy = mag.rows / 2;
  // rearrange the quadrants of Fourier image
  // so that the origin is at the image center
  Mat tmp;
  Mat q0(mag2, Rect(0, 0, cx, cy));
  Mat q1(mag2, Rect(cx, 0, cx, cy));
  Mat q2(mag2, Rect(0, cy, cx, cy));
  Mat q3(mag2, Rect(cx, cy, cx, cy));
  q0.copyTo(tmp);
  q3.copyTo(q0);
  tmp.copyTo(q3);
  q1.copyTo(tmp);
  q2.copyTo(q1);
  tmp.copyTo(q2);

  normalize(mag2, mag2, 0, 1, NORM_MINMAX); //归一化处理，用0-1之间的浮点数将矩阵变换为可视的图像格式
  mag2.convertTo(mag2, CV_8UC1, 255, 0);
  return mag2;
}
