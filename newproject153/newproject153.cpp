#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using  namespace cv;


int main()
{
	//Mat bright;
	//Mat dark;
	//bright = cv::imread("media/outdoor_cube.png");
	//dark = cv::imread("media/indoor_cube.png");
	//
	//Mat brightHSV;
	//Mat darkHSV;
	//cvtColor(bright, brightHSV, cv::COLOR_BGR2HSV);
	//cvtColor(dark, darkHSV, cv::COLOR_BGR2HSV);
	//Vec3b bgrPixel(40, 158, 16);
	//Mat3b bgr(bgrPixel);
	//
	//Mat3b hsv;
	//cvtColor(bgr, hsv, COLOR_BGR2HSV);
	//
	//Vec3b hsvPixel(hsv.at<Vec3b>(0, 0));
	//
	//int thresh = 40;
	//Scalar minHSV = cv::Scalar(hsvPixel.val[0] - thresh, hsvPixel.val[1] - thresh, hsvPixel.val[2] - thresh);
	//Scalar maxHSV = cv::Scalar(hsvPixel.val[0] + thresh, hsvPixel.val[1] + thresh, hsvPixel.val[2] + thresh);
	//
	//Mat maskHSV, resultHSV;
	//inRange(brightHSV, minHSV, maxHSV, maskHSV);
	//bitwise_and(brightHSV, brightHSV, resultHSV, maskHSV);

	//######################

	Mat bright = imread("media/outdoor_cube.png");
	Mat dark = imread("media/indoor_cube.png");
	
	Mat brighthsv;
	cvtColor(bright, brighthsv, COLOR_BGR2HSV);
	
	Vec3b rgb(40, 158, 16);
	Mat3b rgbmat(rgb);
	Mat3b hsvmat;
	cvtColor(rgbmat, hsvmat, COLOR_BGR2HSV);
	Vec3b hsv(hsvmat.at<Vec3b>(0, 0));
	int thres = 40;
	Scalar minhsv = Scalar(hsv.val[0] - thres, hsv.val[1] - thres, hsv.val[2] - thres);
	Scalar maxhsv = Scalar(hsv.val[0] + thres, hsv.val[1] + thres, hsv.val[2] + thres);
	Mat maskhsv;
	Mat hsvoutput;
	inRange(brighthsv, minhsv, maxhsv, maskhsv);
	bitwise_and(brighthsv, brighthsv, hsvoutput, maskhsv);
	//
	int key;
	do
	{
		//imshow("green pixels i guess ??", hsvoutput);
		imshow("Result HSV", hsvoutput);
        key = waitKey(100);
	} while (key != 'q');
	//destroyAllWindows();
	return 0;
}	