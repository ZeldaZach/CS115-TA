#include "Viewer.h"

Viewer::Viewer(cv::String title) :
	  windowTitle(title)
	, viewSobel(false)
	, viewGray(false)
	, viewRed(false)
	, viewGreen(false)
	, viewBlue(false)
{
	//make sure camera can be opened and stream is active
	capture = cv::VideoCapture(0);
	if (!capture.isOpened())
	{
		throw cv::String("Failed to start video capture.");
	}
}
void Viewer::CreateGrayScale()
{
	//convert RGB to grayscale
	cv::cvtColor(image, image, CV_BGR2GRAY);
}
void Viewer::SplitChannels(int channel)
{
	cv::Mat channels[3];
	//split channels into 3 images(B, G, R)
	cv::split(image, channels);
	//Set channels we don't want to use to black
	for (int i = 0; i < 3; ++i)
	{
		if (i != channel)
		{
			channels[i] = cv::Mat::zeros(image.rows, image.cols, CV_8UC1);
		}
	}
	//merge 3 channels back into 1 image
	cv::merge(channels, 3, image);
}
void Viewer::EdgeDetection()
{
	//blur image
	cv::GaussianBlur(image, image, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);
	//convert to gray scale
	cv::cvtColor(image, image, CV_BGR2GRAY);

	//Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;
	cv::Mat abs_grad_x, abs_grad_y;

	//Gradient X
	cv::Sobel(image, grad_x, CV_16S, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_x, abs_grad_x);

	//Gradient Y
	cv::Sobel(image, grad_y, CV_16S, 0, 1, 3, 1, 0, cv::BORDER_DEFAULT);
	cv::convertScaleAbs(grad_y, abs_grad_y);

	//Total Gradient (approximate)
	cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, image);
}
void Viewer::Run()
{
	//Create a window to display tzfgdhe stream on
	cv::namedWindow(windowTitle, cv::WINDOW_NORMAL);

	//Infinite for loop. Checks for user input from the keyboard to exit.
	for (;;)
	{
		//get keyboard input
		int key = cv::waitKey(33);
		//Press Escape key to exit program.
		if (key == 27)
		{
			//exit main loop
			break;
		}
		else if (key == 's')
		{
			viewSobel = true;
			viewGray = false;
			viewRed = false;
			viewBlue = false;
			viewGreen = false;
		}
		else if (key == 'o')
		{
			viewSobel = false;
			viewGray = true;
			viewRed = false;
			viewBlue = false;
			viewGreen = false;
		}
		else if(key == 'i')
		{
			viewSobel = false;
			viewGray = false;
			viewRed = false;
			viewBlue = false;
			viewGreen = false;
		}
		else if (key == 'r')
		{
			viewRed = true;
			viewBlue = false;
			viewGreen = false;
			viewSobel = false;
			viewGray = false;
		}
		else if (key == 'g')
		{
			viewRed = false;
			viewBlue = false;
			viewGreen = true;
			viewSobel = false;
			viewGray = false;
		}
		else if (key == 'b')
		{
			viewRed = false;
			viewBlue = true;
			viewGreen = false;
			viewSobel = false;
			viewGray = false;
		}
		//Capture input from the stream
		capture >> image;
		if (viewSobel)
		{
			EdgeDetection();
		}
		else if (viewGray)
		{
			CreateGrayScale();
		}
		else if (viewRed)
		{
			SplitChannels(2);
		}
		else if (viewBlue)
		{
			SplitChannels(0);
		}
		else if (viewGreen)
		{
			SplitChannels(1);
		}
		cv::imshow(windowTitle, image);
	}
	//Destroys the window when the program exits. This is needed to make sure memory is cleaned up.
	cv::destroyAllWindows();
}