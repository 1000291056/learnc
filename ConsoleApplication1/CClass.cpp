#include "stdafx.h"
#include "CClass.h"
#include <iostream>
using namespace std;
namespace test
{

	void CClass::tellSelf()
	{
		cout << "���ǰ༶�����\n" << endl;
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
		cout << "�༶��	" << (className) << "��ѧ��" << (studentCnt) << endl;
	}
	void CClass::cVirtual()
	{
	}
}