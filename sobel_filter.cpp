#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 0.2126
#define GREEN 0.7152
#define BLUE 0.0722

#define ESC 27

cv::Mat to442_grayscale(cv::Mat& rgbImage);
cv::Mat to442_sobel(cv::Mat& grayscaleImage);

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
		cv::imshow("Processed Frame", grayscale);
		
		//cv::Mat sobelFiltered = to442_sobel(grayscale);
		
		//cv::imshow("Processed Frame", sobelFiltered);
		
		int key = cv::waitKey(30);
		if (key == ESC)
			break;
		
	}
	
	cap.release();
	cv::destroyAllWindows();
	
}

cv::Mat to442_grayscale(cv::Mat& rgbImage)
{	
    cv::Size sz = rgbImage.size();
    int imageWidth = sz.width;
    int imageHeight = sz.height;

    int i = 0; // width (column) index
    int j = 0; // height (row) index
    for (i = 0; i < imageWidth; i++)
    {
        for (j = 0; j < imageHeight; j++)
        {
            cv::Vec3b& pixel = rgbImage.at<cv::Vec3b>(j, i); // Vec<uchar, 3>
            uchar blue = pixel[0];
            uchar green = pixel[1];
            uchar red = pixel[2];
            
            blue = blue * BLUE;
            green = green * GREEN;
            red = red * RED;
            
            uchar gray = blue + green + red;

            pixel[0] = gray;
            pixel[1] = gray;
            pixel[2] = gray;

            //rgbImage.at<cv::Vec3b>(j, i) = pixel;
        }
    }
    return rgbImage;
}

cv::Mat to442_sobel(cv::Mat& grayscaleImage) {
	
	}
