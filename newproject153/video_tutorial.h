#ifdef pran
#def pran
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>

using  namespace cv;

int main() {

    //std::string path = "media/Cars.mp4";
    //VideoCapture vid_capture(path);
    VideoCapture vid_capture("Resources/Image_sequence/Cars%04d.jpg");

    if (!vid_capture.isOpened())
    {
        std::cout << "Failed to open video";
        std::exit(0);
    }
    else
    {
        int fps = vid_capture.get(5);
        std::cout << "video FPS are : " << fps << std::endl;
        int frame_count = vid_capture.get(7);
        std::cout << "video FPS are : " << frame_count << std::endl;
    }
    waitKey(0);
    while (vid_capture.isOpened())
    {
        Mat frame;
        bool video = vid_capture.read(frame);
        if (video)
        {
            imshow("Frame", frame);
        }
        if (!video)
        {
            std::cout << "Video camera disconnected";
            break;
        }
        int key = waitKey(10);
        if (key == 'q')
        {
            std::cout << "exiting" << '\n';
            break;
        }

    }


    return 0;

}
#endif
