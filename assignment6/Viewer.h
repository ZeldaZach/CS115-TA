#ifndef VIEWER_H
#define VIEWER_H
#include <opencv2/opencv.hpp>

class Viewer
{
public:
	//Constructor that takes a string as a parameter.
	Viewer(cv::String title);
	//Main function for the viewer. This will contain your new code.
	void Run();

private:
	//title of window
	cv::String windowTitle;
	//current image from stream
	cv::Mat image;
	//video stream
	cv::VideoCapture capture;
	void EdgeDetection();
	void CreateGrayScale();
	void SplitChannels(int channel);
	bool viewSobel;
	bool viewGray;
	bool viewRed;
	bool viewGreen;
	bool viewBlue;
};
#endif