#ifdef pran
#define pran
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using  namespace cv;

int main()
{
	VideoCapture vid_capture(0);

	int width = static_cast<int>(vid_capture.get(3));
	int height = static_cast<int>(vid_capture.get(4));
	Size size(width, height);
	int fps = 5;
	VideoWriter output("output/output_video.mp4", VideoWriter::fourcc('M', 'J', 'P', 'G'), fps, size);

	while (vid_capture.isOpened())
	{
		Mat frame;
		bool video = vid_capture.read(frame);
		if (!video)
		{
			std::cout << "There are no frame to read !! ";
			break;
		}
		if (video)
		{
			output.write(frame);
			imshow("frame", frame);
			int key = waitKey(100);
			if (key == 'q')
			{
				std::cout << "Exiting";
				break;
			}
		}

	}
	vid_capture.release();
	output.release();
	std::cin.get();
}


#endif 
