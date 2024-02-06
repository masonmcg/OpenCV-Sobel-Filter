#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <video_file>" << std::endl;
        return 1;
    }
    
    cv::VideoCapture cap(argv[1]);
    if (!cap.isOpened()) {
		std::cerr << "Error: Couldn't open the video file." << std::endl;
        return 1;
	}
	
	while (true) {
		
		cv::Mat frame;
		cap >> frame;
		if (frame.empty())
			break;
			
		cv::Mat grayscale = to442_grayscale(frame);
		
		cv::Mat sobelFiltered = to442_sobel(grayscale);
		
		cv::imshow("Processed Frame", sobelFiltered);
		
		int key = cv::waitKey(30);
		if (key == 27)
			break;
		
	}
	
	cap.release();
	cv::destroyAllWindows();
	
}

cv::Mat to_442_grayscale(const cv::Mat& rgbImage)
{
    cv::Size sz = image.size();
    int imageWidth = sz.width;
    int imageHeight = sz.height;

    int i = 0; // width (column) index
    int j = 0; // height (row) index
    for (i = 0; i < imageWidth; i++)
    {
        for (j = 0; j < imageHeight; j++)
        {
            cv::Vec3b pixel = rgbImage.at<cv::Vec3b>(j, i); // Vec<uchar, 3>
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            
            blue = blue * BLUE;
            green = green * GREEN;
            red = red * RED;

            pixel[0] = blue;
            pixel[1] = green;
            pixel[2] = red;

            rgbImage.at<cv::Vec3b>(j, i) = pixel;
        }
    }
    return rbgImage;
}

cv::Mat to442_sobel(const cv::Mat& grayscaleImage) {
	
	}
