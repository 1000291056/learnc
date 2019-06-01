#pragma once

#include <string>
using namespace std;
class Tree
{
public:
	string name;
	Tree* p;
	Tree* left;
	Tree* right;
	Tree();
	~Tree();
	
	


};

class TreeList
{
public:
		void insertNode(Tree tree);
};