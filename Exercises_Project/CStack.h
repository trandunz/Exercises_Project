#pragma once
#include "CSingleLinkList.h"
class CStack : CSingleLinkList
{
public:
	CStack();
	~CStack();

	void Push(int _iData);
	void Pop(int _iData);
	void Pop();
	void Peek();
	bool IsEmpty();
};

