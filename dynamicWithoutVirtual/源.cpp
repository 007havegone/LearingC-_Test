#include <cstdio>

struct StBaseInfo
{
	int nID;
	//virtual ~StBaseInfo() = default;
};

struct StExtendInfo : public StBaseInfo
{
	int nAnything;
	//~StExtendInfo() = default;
};

int main()
{
	StBaseInfo* pBaseInfo = new StExtendInfo;
	//û���麯���޷�ʹ��dynamic
	StExtendInfo* pExInfo = dynamic_cast<StExtendInfo*>(pBaseInfo);

	delete pBaseInfo;
	pBaseInfo = NULL;

	return 0;
}