#pragma once
namespace test
{
	class CSchook
	{
	public:
		void tellSelf();
		CSchook();
		CSchook(char *schoolName, int classCnt);
		~CSchook();
	private:
		int classCnt;
		char schoolName[256];
		void tellInfo();
	};
	class Node
	{
	public:
		Node();
		~Node();
		Node(int data);
		void printSelf();
		int data;
		Node* next;

	private:

	};
	template <class Type>
	class NodeList
	{
	public:
		NodeList();
		~NodeList();
		int count;
		Type* head;
		Type* moveToTrail(bool print);
		void add(Type* node);
		void revertList();//·´×ªÁ´±í

		void printInfo();

	private:
		void destroyList();
	};

}
