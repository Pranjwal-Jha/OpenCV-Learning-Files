#pragma once
#ifdef pran
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using  namespace cv;
//IMAGE ROTATION USING OPENCV


int main()
{
	Mat img = imread("media/ship.png");
	int width = img.size().width;
	int height = img.size().height;
	float tx = width / 4;
	float ty = height / 4;
	float wrap_values[] = { 1.0,0.0,tx,0.0,1.0,ty };
	Mat translation_matrix = Mat(2, 3, CV_32F, wrap_values);
	Mat translated_image;
	warpAffine(img, translated_image, translation_matrix, img.size());
	int key;
	do
	{
		imshow("translated image", translated_image);
		imwrite("output/translated_image.png", translated_image);
		key = waitKey(100);

	} while (key != 'q');
	return 0;
}

#endif
