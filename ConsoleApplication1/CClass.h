#pragma once
#include "CGroup.h"
namespace test
{
	class CClass:public CGroup
	{
	public:
		void tellSelf();

		CClass();
		CClass(char*className, int studentCnt);

		~CClass();
	private:
		int studentCnt;
		char className[256];
		void tellInfo();

		void cVirtual();

	};
}


