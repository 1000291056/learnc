#include "stdafx.h"
#include "CSchook.h"
#include <iostream>

using namespace std;
namespace test
{
	void CSchook::tellSelf()
	{
		cout << "我是学校情况 \n" << endl;
	}

	CSchook::CSchook()
	{
	}

	CSchook::CSchook(char * schoolName, int classCnt)
	{
		strcpy_s(this->schoolName, schoolName);
		this->classCnt = classCnt;
	}


	CSchook::~CSchook()
	{
	}

	void CSchook::tellInfo()
	{
		cout << "学校" << schoolName << "  有班级" << classCnt << endl;
	}
	
	Node::Node()
	{
		next = NULL;
	}

	Node::~Node()
	{
	}

	Node::Node(int data)
	{
		this->data = data;
	}

	void Node::printSelf()
	{
		cout << "我的数据" << data << endl;
	}
	

}
