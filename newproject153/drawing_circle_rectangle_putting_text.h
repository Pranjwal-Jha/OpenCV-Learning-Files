#pragma once
#ifdef pran
Mat img = imread("media/dog.jpg");
//imshow("dog", img);
Mat line_image = img.clone();
Point pointA(20, 80);
Point pointB(600, 500);
line(line_image, pointA, pointB, Scalar(255, 255, 0), 3, 8, 0);
Point center(400, 190);
int radius{ 100 };
Mat circle_image = img.clone();
circle(circle_image, center, radius, Scalar(0, 0, 255), 1, 8, 0);
Mat rectangle_image = img.clone();
rectangle(rectangle_image, pointA, pointB, Scalar(255, 255, 0), 3, 8, 0);
Mat text_image = img.clone();
putText(text_image, "my wife will love me very much", pointA, 0, 1, Scalar(255, 0, 0));


int key;
do
{
	imshow("text image ", text_image);
	//imshow("rectangle", rectangle_image);
	//imshow("circle_dog", circle_image);
	//imshow("dog", line_image);
	key = waitKey(100);
} while (key != 'q');
destroyAllWindows();

#endif

