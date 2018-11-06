#include "stdafx.h"
#include "CClass.h"
#include <iostream>
using namespace std;
namespace test
{

	void CClass::tellSelf()
	{
		cout << "我是班级情况！\n" << endl;
	}

	CClass::CClass()
	{

	}
	CClass::CClass(char*className, int studentCnt) :CClass()
	{
		strcpy(this->className, className);
		this->studentCnt = studentCnt;

	}

	CClass::~CClass()
	{
	}
	void CClass::tellInfo()
	{
		cout << "班级：	" << (className) << "有学生" << (studentCnt) << endl;
	}
	void CClass::cVirtual()
	{
	}
}