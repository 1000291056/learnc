#pragma once

namespace test
{

	class CGroup
	{
	public:
		virtual void cVirtual() = 0;
		void base();
		CGroup();
		~CGroup();
	};
}


