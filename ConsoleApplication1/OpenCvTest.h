#pragma once
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include<string>
using namespace std;
using namespace cv;
class OpenCvTest
{
public:
	std::string imagePath;
	OpenCvTest();
	~OpenCvTest();
	/**
	��ת����ʾimg
	*/
	void rotateAndShow(string path,int angle=0);
	Mat rotateImg(string path, int angle=0);
	void showImg(string path);
	void detectAndShowImg(string path);
	/**/
	void detectAndShowImg(string path,bool needRotate=false,int angle=0);

};

