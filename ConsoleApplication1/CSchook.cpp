#include "stdafx.h"
#include "CSchook.h"
#include <iostream>

using namespace std;
namespace test
{
	void CSchook::tellSelf()
	{
		cout << "����ѧУ��� \n" << endl;
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
		cout << "ѧУ" << schoolName << "  �а༶" << classCnt << endl;
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
		cout << "�ҵ�����" << data << endl;
	}
	

}
