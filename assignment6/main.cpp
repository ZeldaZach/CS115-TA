#include "Viewer.h"
#include <memory>
#include <iostream>

int main()
{
	try
	{
		std::unique_ptr<Viewer> viewer(new Viewer("Stream Viewer"));
		viewer->Run();
	}
	catch (cv::String out)
	{
		//Simply print out the error/problem and exit.
		std::cout << out << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}