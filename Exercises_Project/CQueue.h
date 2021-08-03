#pragma once
#include "CSingleLinkList.h"
class CQueue :	private CSingleLinkList
{
public:
	CQueue();
	~CQueue();

	void Enqueue(int _iData);
	void Enqueue_Back(int _iData);
	void Enqueue_Front(int _iData);

	void Dequeue(int _iData);
	void Dequeue();

	void Dequeue_Back(int _iData);
	void Dequeue_Back();

	void Dequeue_Front(int _iData);
	void Dequeue_Front();

	void Peek();
	void Peek_Front();
	void Peek_Back();

	bool IsEmpty();
};

