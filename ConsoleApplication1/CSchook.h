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


}
