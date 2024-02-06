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

cv::Mat to442_grayscale(const cv::Mat& rgbImage) {
	
	}

cv::Mat to442_sobel(const cv::Mat& grayscaleImage) {
	
	}
