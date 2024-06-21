#pragma once
#ifdef pran
Mat img = imread("media/ship.png");
Point2f center((img.cols - 1) / 2.0, (img.rows - 1) / 2.0);
//Point2f center((img.size().width - 1) / 2.0), (img.size().height - 1) / 2.0);
Mat rotation_matrix = getRotationMatrix2D(center, 45, 1.0);
Mat rotated_image_user;
warpAffine(img, rotated_image_user, rotation_matrix, img.size());
int key;
do
{
	imshow("rotated image", rotated_image_user);
	imwrite("output/rotatedimage.png", rotated_image_user);
	key = waitKey(100);
} while (key != 'q');
#endif