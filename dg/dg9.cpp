#include"dg.h"
using namespace cv;
cv::Mat testimage(cv::Mat img) {
  return img;
}
Mat dftImage(Mat img) {
  if (img.channels() != 1) {
    cvtColor(img, img, COLOR_BGR2GRAY); //单通道灰度图
  }
  Mat padded;//填充后的图像
  int M = getOptimalDFTSize(img.rows); //将输入图像延扩到最佳的尺寸, 边界用0补充
  int N = getOptimalDFTSize(img.cols);
  copyMakeBorder(img, padded, 0, M - img.rows, 0, N - img.cols, BORDER_CONSTANT, Scalar::all(0));//填充图像保存到padded中

  Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)}; //为傅立叶变换的结果(实部和虚部)分配存储空间, planes[0]为实数部分，planes[1]为虚数部分, planes[2]为幅度, planes[3]为相位, planes[4]为幅度的对数, planes[5]为相位的对数, planes[6]为幅度的归一化, planes[7]为相位的归一化, planes[8]为幅度的对数的归一化, planes[9]为相位的对数的归一化, planes[10]为幅度的对数的归一化的平滑, planes[11]为相位的对数的归一化的平滑
  Mat complexImg;//复数转换结果
  merge(planes, 2, complexImg); //为延扩后的图像增添一个初始化为0的通道
  dft(complexImg, complexImg); //进行离散傅立叶变换

  // compute log(1 + sqrt(Re(DFT(img))**2 + Im(DFT(img))**2))  将实数和复数的值转换为幅度值
  split(complexImg, planes);//将多通道的数组分离成几个单通道的数组
  magnitude(planes[0], planes[1], planes[0]);//将实数和虚数部分转换为幅度
  Mat mag = planes[0];//幅度
  mag += Scalar::all(1); //转换为对数尺度
  log(mag, mag);//求自然对数
  // crop the spectrum, if it has an odd number of rows or columns
  mag = mag(Rect(0, 0, mag.cols, mag.rows)); //如果有奇数行或列，则对频谱进行裁剪

  Mat mag2 = mag.clone();
  normalize(mag, mag, 0, 1, NORM_MINMAX); //归一化处理，用0-1之间的浮点数将矩阵变换为可视的图像格式
  mag.convertTo(mag, CV_8UC1, 255, 0);//转换为8位无符号整型

  int cx = mag.cols / 2;//以下部分为了将图像的低频部分移动到图像中心
  int cy = mag.rows / 2;//以下部分为了将图像的低频部分移动到图像中心
  // rearrange the quadrants of Fourier image
  // so that the origin is at the image center
  Mat tmp;//以下部分为了将图像的低频部分移动到图像中心
  Mat q0(mag2, Rect(0, 0, cx, cy));//左上角图像划定ROI区域
  Mat q1(mag2, Rect(cx, 0, cx, cy));//右上角图像
  Mat q2(mag2, Rect(0, cy, cx, cy));//左下角图像
  Mat q3(mag2, Rect(cx, cy, cx, cy));//右下角图像
  q0.copyTo(tmp);//左上角图像像素复制到tmp
  q3.copyTo(q0);//右下角图像复制到左上角
  tmp.copyTo(q3);//tmp复制到右下角
  q1.copyTo(tmp);//右上角复制到tmp
  q2.copyTo(q1);//右上角复制到左下角
  tmp.copyTo(q2);//tmp复制到左下角

  normalize(mag2, mag2, 0, 1, NORM_MINMAX); //归一化处理，用0-1之间的浮点数将矩阵变换为可视的图像格式, 用于显示
  mag2.convertTo(mag2, CV_8UC1, 255, 0);//转换为8位无符号整型
  return mag2;//返回结果
}
