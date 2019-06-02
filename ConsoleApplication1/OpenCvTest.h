#pragma once
#include<opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include<string>
using namespace std;
using namespace cv;
struct Path
{
	string path;
};
class OpenCvTest
{
public:
	std::string imagePath;
	OpenCvTest();
	~OpenCvTest();
	/**
	Ðý×ª²¢ÏÔÊ¾img
	*/
	void rotateAndShow(string path,int angle=0);
	Mat rotateImg(string path, int angle=0);
	void showImg(string path);
	void detectAndShowImg(string path);
	/**/
	void detectAndShowImg(string path,bool needRotate=false,int angle=0);
	void detectAndShowImg(Path &pathStruct, bool needRotate, int angle);
	void detectAndShowImg(Path* pathStruct, bool needRotate, int angle);

};

