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
	imshow("��Ů", img);
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
	//����ʶ��ģ��
	loader.load(modulePath);
	//��ȡԭͼƬ
	Mat imgResource;
	//������ת �򱣴���ת֮ǰ��ͼƬ
	Mat oldImg;
	if (needRotate)
	{
		imgResource = rotateImg(path, angle);
	}
	else
	{
		imgResource = imread(path);

	}
	//�Ҷ�ͼ
	Mat imgGray;
	//ת��Ϊ�Ҷ�ͼ
	cvtColor(imgResource, imgGray, ColorConversionCodes::COLOR_RGB2GRAY);
	equalizeHist(imgGray, imgGray);
	//ʶ�����������λ��
	vector<Rect>faces;
	loader.detectMultiScale(imgGray, faces);
	//ʶ�����������
	size_t count = faces.size();
	//��һ������
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
			imshow("ʶ����", imgResource);
		/*}
		else
		{*/
			//��������
			oldImg = imread(path);
			rectangle(oldImg, faces[0], Scalar(0, 0, 255), 2, 8, 0);
			imshow("�����ʶ����", oldImg);
		/*}*/


		waitKey(6000);
	}
	else
	{
		cout << "û��ʶ������������" << endl;
	}

}

