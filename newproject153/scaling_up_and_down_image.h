#pragma once
#ifdef pran
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using  namespace cv;

int main()
{
	Mat image = imread("media/WIN_20221231_20_42_06_Pro.jpg");
	int width = 300;
	int height = 180;
	Mat resize_down;
	resize(image, resize_down, Size(width, height), INTER_LINEAR);
	double scale_up_x = 1.2;
	double scale_up_y = 1.2;
	double scale_down = 0.6;
	Mat scaled_up, scaled_down;
	resize(image, scaled_down, Size(), scale_down, scale_down, INTER_LINEAR);
	resize(image, scaled_up, Size(), scale_up_x, scale_up_y, INTER_LINEAR);
	int key;
	do
	{
		imwrite("output/pranjwal_image.jpg", scaled_up);
		imshow("scaled sized down image", scaled_up);
		key = waitKey(100);
	} while (key != 'q');

	return 0;
}
#endif
