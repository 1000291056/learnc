// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "CSchook.h"
#include "CClass.h"
#include "OpenCvTest.h"
#include <iostream>
#include <fstream>
#define PI 3.14159268
#define BUFFER_SIZE 256
using namespace std;
using namespace test;
static int i = 0;
void swap(int &&, int &&);
void testStruct();
void testEnum();
void testClass();
void testTp();
void testLink();
void testStream();
//function template

int main()
{
	int c = 1;
	cout << ("hello world\n");
	printf("c=%4d\n", c);
	//数组指针
	int array[] = { 1,2,3,4,5,6 };
	int *p = array;
	for (size_t i = 0; i < 6; i++)
	{
		cout << ("%4d", *(p++));
		if ((i + 1) % 3 == 0)
		{
			cout << "\n" << endl;
		}
	}

	//swap(30, 6);
	//testStruct();
	//testEnum();
	//testClass();
	//testTp();
	//testLink();
	//testStream();
	OpenCvTest opencv;
	string  path = "E:\\Picture\\chounv.jpg";
	string  pathRotate = "E:\\Picture\\chounvrote.jpg";
	Path pathStru1;
	Path *pathStru=&pathStru1;
	pathStru->path = pathRotate;
	opencv.detectAndShowImg(pathStru,true,90);
	/*opencv.detectAndShowImg(pathRotate);*/

	system("pause");
	return 0;
}




void testLink() {
	test::NodeList<test::Node> nodelist;
	test::Node *node1 =new test::Node(1);
	test::Node *node2 =new test::Node(2);
	test::Node *node3 =new test::Node(3);
	test::Node *node4 =new test::Node(4);
	test::Node *node5 =new test::Node(5);
	test::Node *node6 =new test::Node(6);
	/*node1.next = NULL;
	node2.next = NULL;
	node3.next = NULL;
	node4.next = NULL;
	node5.next = NULL;
	node6.next = NULL;*/
	nodelist.add(node1);
	nodelist.add(node2);
	nodelist.add(node3);
	nodelist.add(node4);
	nodelist.add(node5);
	nodelist.add(node6);
	nodelist.printInfo();
	cout << "<<<<<<<<<<<<<<<"<<endl;
	nodelist.revertList();
	nodelist.printInfo();
	cout << "<<<<<<<<<<<<<<<" << endl;
	nodelist.revertList();
	nodelist.printInfo();
	cout << "<<<<<<<<<<<<<<<" << endl;
	nodelist.revertList();
	nodelist.printInfo();
	cout << "<<<<<<<<<<<<<<<" << endl;
	nodelist.revertList();
	nodelist.printInfo();

}
void testStream()
{
	const char *filePath = "C:\\Users\\temp\\Desktop\\cstream.txt";
	fstream fs;
	try
	{

	}
	catch (const std::exception&)
	{

	}
	fs.open(filePath, ios::in);
	if (!fs.fail())
	{
		while (!fs.eof())
		{
			char buff[BUFFER_SIZE];
			fs.getline(buff, BUFFER_SIZE);
			cout << buff<<endl;
		}
		
	}
	else
	{
		cout << "文件打开失败了！！！";
	}
	fs.close();
}

template<class Type>
NodeList<Type>::NodeList()
{
	count = 0;
}
template<class Type>
NodeList<Type>::~NodeList()
{
	cout << "~NodeList"<<endl;
	destroyList();
	printInfo();
}
template<class Type>
Type* NodeList<Type>::moveToTrail(bool print)
{
	if (count <= 0)
	{
		cout << "节点无数据！" << endl;
		return NULL;
	}
	Type * temp = NULL;
	do {
		temp = (temp == NULL) ? head : temp->next;
		if (print)
		{
			temp->printSelf();
		}
	} while (temp->next != NULL);
	return temp;
}
template<class Type>
void NodeList<Type>::add(Type *node)
{

	if (count == 0)
	{
		head = node;
		count++;
	}
	else
	{
		Type *temp = moveToTrail(false);
		if (temp==NULL)
		{
			return;
		}
		temp->next = node;
		count++;
	}
}
template<class Type>
void NodeList<Type>::revertList()
{
	Type * beforeNode = head;
	Type *afterNode = beforeNode->next;
	Type *temp = afterNode->next;
	while (true)
	{
		afterNode->next = beforeNode;
		beforeNode = afterNode;
		afterNode = temp;
		if (afterNode==NULL)
		{
			head->next = NULL;
			head = beforeNode;
			
			return;
		}
		temp = temp->next;
	} 
	

}
template<class Type>
void NodeList<Type>::destroyList()
{

	Type *tempNode;//暂时保持连接的节点
	Type *deleteNode= head;//获取节点删除
	while (count > 0)
	{
		tempNode =deleteNode->next;
		delete deleteNode;
		deleteNode = tempNode;
		count--;
	}

}
template<class Type>
void NodeList<Type>::printInfo()
{
	moveToTrail(true);
}
template<class Type>
Type testFunTp(Type a, Type b)
{
	Type temp = (a > b) ? a : b;
	cout << "test template function:" << temp << endl;
	return temp;
}
//class template
template <class Type>
class ClassTp
{
public:
	Type t;
	void printTpMember(Type temp);

};
//class_function
template <class TypeF>
void ClassTp <TypeF>::printTpMember(TypeF t)
{
	cout << t << endl;
}
enum Week
{
	One, TWO, THREE
};
void testEnum()
{
	Week w = One;
	Week w1 = THREE;
	cout << "w1 + w=" << (w1 + w) << endl;
}
void swap(int &&a, int &&b) {
	i = (a > b ? a : b);
	cout << ("右值引用i=%5d", i) << endl;
}
struct Student
{
	int age;
	char name[60];
	void(*fun)(Student *);
} stu;
void fun(Student* stu)
{
	cout << "student: " << stu->name << " is " << stu->age << " old" << endl;
}

void testStruct() {
	stu.age = 12;
	strcpy_s(stu.name, "student");
	stu.fun = fun;
	stu.fun(&stu);
}
void testClass() {
	char schName[] = "上海师范大学";
	CSchook sch(schName, 50);
	sch.tellSelf();
	char className[] = "机械设计";
	CClass cClass(className, 45);
}
void testTp() {
	testFunTp(2, 1);
	ClassTp <int> ct;
	ct.printTpMember(23);
}

