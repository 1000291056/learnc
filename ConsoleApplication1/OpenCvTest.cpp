#include "stdafx.h"
#include "OpenCvTest.h"


OpenCvTest::OpenCvTest()
{
}

OpenCvTest::~OpenCvTest()
{

}
void OpenCvTest::rotateAndShow(string path, int angle)
{
	cv::Mat src = cv::imread(path);
	cv::imshow("src", src);
	cv::Point2f center(src.cols / 2, src.rows / 2);
	cv::Mat rot = cv::getRotationMatrix2D(center, angle, 1);
	cv::Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();

	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::Mat dst;
	cv::warpAffine(src, dst, rot, bbox.size());
	cv::imshow("dst", dst);
	cv::waitKey(0);
}
Mat OpenCvTest::rotateImg(string path, int angle)
{
	Mat src = imread(path);
	Point2f center(src.cols / 2, src.rows / 2);
	Mat rot = cv::getRotationMatrix2D(center, angle, 1);
	Rect bbox = cv::RotatedRect(center, src.size(), angle).boundingRect();

	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::Mat dst;
	cv::warpAffine(src, dst, rot, bbox.size());
	return dst;
}
void OpenCvTest::showImg(string path)
{

	Mat img = imread(path);
	imshow("丑女", img);
	waitKey(6000);
}

void OpenCvTest::detectAndShowImg(string path)
{
	detectAndShowImg(path, false);
}

void OpenCvTest::detectAndShowImg(string path, bool needRotate, int angle)
{
	string modulePath = "D:\\Tool\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_alt.xml";
	CascadeClassifier loader;
	//加载识别模型
	loader.load(modulePath);
	//读取原图片
	Mat imgResource;
	//若有旋转 则保存旋转之前的图片
	Mat oldImg;
	if (needRotate)
	{
		imgResource = rotateImg(path, angle);
	}
	else
	{
		imgResource = imread(path);

	}
	//灰度图
	Mat imgGray;
	//转化为灰度图
	cvtColor(imgResource, imgGray, ColorConversionCodes::COLOR_RGB2GRAY);
	equalizeHist(imgGray, imgGray);
	//识别的所有人脸位置
	vector<Rect>faces;
	loader.detectMultiScale(imgGray, faces);
	//识别的人脸个数
	size_t count = faces.size();
	//拿一个人脸
	Rect faceFirst;
	if (count > 0)
	{
		faceFirst.x = faces[0].x;
		faceFirst.y = faces[0].y;
		faceFirst.width = faces[0].width;
		faceFirst.height = faces[0].height;
		/*if (!needRotate)
		{*/
			rectangle(imgResource, faces[0], Scalar(0, 0, 255), 2, 8, 0);
			imshow("识别结果", imgResource);
		/*}
		else
		{*/
			//仅供测试
			oldImg = imread(path);
			rectangle(oldImg, faces[0], Scalar(0, 0, 255), 2, 8, 0);
			imshow("故意假识别结果", oldImg);
		/*}*/


		waitKey(6000);
	}
	else
	{
		cout << "没有识别到人脸！！！" << endl;
	}

}

