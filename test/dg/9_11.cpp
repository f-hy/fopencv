#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#define dg "E:/data/courses/dg/"
#define dgdata dg "static/"
Mat img = imread(dgdata "9_11.png", IMREAD_GRAYSCALE);  // IMREAD_GRAYSCALE
int main() {
  // Perform the Fourier Transform
  Mat imgFreq;
  dft(img, imgFreq, DFT_COMPLEX_OUTPUT);

  // Split the complex image into real and imaginary parts
  Mat planes[2];
  split(imgFreq, planes);

  // Compute the magnitude spectrum (power spectrum)
  Mat mag;
  magnitude(planes[0], planes[1], mag);

  // Move the quadrants to the center
  int cx = mag.cols / 2;
  int cy = mag.rows / 2;
  Mat q0(mag, Rect(0, 0, cx, cy));
  Mat q1(mag, Rect(cx, 0, cx, cy));
  Mat q2(mag, Rect(0, cy, cx, cy));
  Mat q3(mag, Rect(cx, cy, cx, cy));
  Mat tmp;
  q0.copyTo(tmp);
  q3.copyTo(q0);
  tmp.copyTo(q3);
  q1.copyTo(tmp);
  q2.copyTo(q1);
  tmp.copyTo(q2);

  // Normalize the magnitude spectrum for display
  normalize(mag, mag, 0, 1, NORM_MINMAX);

  // Display the power spectrum
  imshow("Power Spectrum", mag);
  waitKey(0);
  // Destroy all windows
  destroyAllWindows();
  return 0;
}