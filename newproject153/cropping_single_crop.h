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
	Mat img = imread("media/testimage.png");
	std::cout << "width of image is :" << img.size().width << '\n';
	std::cout << "height of image is :" << img.size().height << '\n';
	std::cout << "channels : " << img.channels() << '\n';
	Mat cropped_img = img(Range(80, 280), Range(150, 330));
	imshow("cropped image", cropped_img);
	waitKey(0);
	destroyAllWindows();

	return 0;
}
#endif
