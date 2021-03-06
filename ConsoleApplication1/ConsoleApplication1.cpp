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
void swap(int&&, int&&);
void testStruct();
void testEnum();
void testClass();
void testTp();
void testLink();
void testStream();
void bubbleSort();
void testVect();
struct BinaryTree
{
	string text;
	int index = 0;
	BinaryTree* left;//左孩子
	BinaryTree* right;//右孩子
	BinaryTree* parent;//父节点

}root;
void insert(BinaryTree*, BinaryTree*);
void testBinaryTree();
BinaryTree* makeBinaryTree();
void ergodicBinaryTree(BinaryTree* root);

//function template

int main()
{
	//int c = 1;
	//cout << ("hello world\n");
	//printf("c=%4d\n", c);
	////数组指针
	//int array[] = { 1,2,3,4,5,6 };
	//int* p = array;
	//for (size_t i = 0; i < 6; i++)
	//{
	//	cout << ("%4d", *(p++));
	//	if ((i + 1) % 3 == 0)
	//	{
	//		cout << "\n" << endl;
	//	}
	//}

	//swap(30, 6);
	//testStruct();
	//testEnum();
	//testClass();
	//testTp();
	//testLink();
	//testStream();
	//OpenCvTest* opencv = new OpenCvTest;
	//string  path = "E:\\Picture\\chounv.jpg";
	//string  pathRotate = "E:\\Picture\\chounvrote.jpg";
	//Path pathStru1;
	//Path* pathStru = &pathStru1;
	//pathStru->path = pathRotate;
	//opencv->detectAndShowImg(pathStru, true, 90);
	//free(opencv);

	/*opencv.detectAndShowImg(pathRotate);*/
	//testBinaryTree();
	//bubbleSort();
	testVect();
	system("pause");
	return 0;
}
/*
冒泡排序
*/
void bubbleSort()
{
	int originArray[] = { 2,6,4,9,7,5 };
	int i = 0, j = 0;
	int length = sizeof(originArray) / sizeof(int);
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < length - 1; j++)
		{
			if (originArray[i] < originArray[i + 1]) {
				int temp = originArray[i];
				originArray[i] = originArray[i + 1];
				originArray[i + 1] = temp;
			}

		}

	}
	for (size_t i = 0; i < length; i++)
	{
		cout << originArray[i] << endl;
	}
}

void testBinaryTree() {
	//makeBinaryTree();

	root.index = 8;
	BinaryTree* left = new BinaryTree();
	left->index = 1;
	BinaryTree* right = new BinaryTree();
	right->index = 5;
	BinaryTree* right1 = new BinaryTree();
	right1->index = 9;
	BinaryTree* right2 = new BinaryTree();
	right2->index = 2;
	BinaryTree* right3 = new BinaryTree();
	right3->index = 7;
	BinaryTree* right4 = new BinaryTree();
	BinaryTree* right5 = new BinaryTree();
	right4->index = 8;
	right5->index = 6;
	insert(&root, left);
	insert(&root, right);
	insert(&root, right1);
	insert(&root, right2);
	insert(&root, right3);
	insert(&root, right4);
	insert(&root, right5);
	ergodicBinaryTree(&root);
}
/*
生成二叉树*/
BinaryTree* makeBinaryTree() {
	//定义根节点
	root.text = "root";
	root.index = 1;
	//根左节点
	BinaryTree* left = new BinaryTree();
	left->text = "text";
	left->parent = &root;
	//根右节点
	BinaryTree* right = new BinaryTree();
	right->text = "right";
	right->parent = &root;
	root.left = left;
	root.right = right;
	return &root;
}
void insert(BinaryTree* position, BinaryTree* b) {
	if (b == nullptr) {
		return;
	}

	if (b->index <= position->index)
	{
		if (position->left == nullptr)
		{
			position->left = b;
			b->parent = position;
		}
		else
		{
			insert(position->left, b);
		}

	}
	else
	{
		if (position->right == nullptr)
		{
			position->right = b;
			b->parent = position;
		}
		else
		{
			insert(position->right, b);
		}
	}


}

void getInsertPostion(BinaryTree* tree, BinaryTree insertTree) {

}
/*
遍历二叉树
*/
void ergodicBinaryTree(BinaryTree* root) {
	if (root == nullptr)
	{
		return;
	}
	if (root->parent == nullptr)
	{
		std::cout << "root信息" << root->index << endl;
	}

	BinaryTree* left = root->left;
	if (left != nullptr) {
		std::cout << "left信息" << left->index << endl;
		ergodicBinaryTree(left);
	}
	BinaryTree* right = root->right;
	if (right != nullptr) {
		std::cout << "right信息" << right->index << endl;
		ergodicBinaryTree(right);
	}

}
void testLink() {
	test::NodeList<test::Node> nodelist;
	test::Node* node1 = new test::Node(1);
	test::Node* node2 = new test::Node(2);
	test::Node* node3 = new test::Node(3);
	test::Node* node4 = new test::Node(4);
	test::Node* node5 = new test::Node(5);
	test::Node* node6 = new test::Node(6);
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
	cout << "<<<<<<<<<<<<<<<" << endl;
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
	const char* filePath = "C:\\Users\\temp\\Desktop\\cstream.txt";
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
			cout << buff << endl;
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
	cout << "~NodeList" << endl;
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
	Type* temp = NULL;
	do {
		temp = (temp == NULL) ? head : temp->next;
		if (print)
		{
			temp->printSelf();
		}
	} while (temp->next != nullptr);
	return temp;
}
template<class Type>
void NodeList<Type>::add(Type* node)
{

	if (count == 0)
	{
		head = node;
		count++;
	}
	else
	{
		Type* temp = moveToTrail(false);
		if (temp == NULL)
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
	Type* beforeNode = head;
	Type* afterNode = beforeNode->next;
	Type* temp = afterNode->next;
	while (true)
	{
		afterNode->next = beforeNode;
		beforeNode = afterNode;
		afterNode = temp;
		if (afterNode == NULL)
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

	Type* tempNode;//暂时保持连接的节点
	Type* deleteNode = head;//获取节点删除
	while (count > 0)
	{
		tempNode = deleteNode->next;
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
void swap(int&& a, int&& b) {
	i = (a > b ? a : b);
	cout << ("右值引用i=%5d", i) << endl;
}
struct Student
{
	int age;
	char name[60];
	void(*fun)(Student*);
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
void testVect()
{
	cout << "################################";
std:vector<int> v;
	v.push_back(1);
	v.push_back(10);
	v.push_back(5);
	v.push_back(7);
	v.push_back(23);
	v.push_back(188);
	vector<int>::iterator i = v.begin();
	cout << "向量大小：" << v.size() << endl;
	for (vector<int>::iterator i = v.begin(); i!=v.end(); i++)
	{
		cout << *i << endl;
	}
	
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

