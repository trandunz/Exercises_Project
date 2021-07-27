#pragma once
#include "CNode.h"

class CSingleLinkList
{
private:
	CNode* firstNode;

public:
	CSingleLinkList();

	~CSingleLinkList();

	void insertAtTheFront(int data);

	void insertInTheMiddle(int data, int position);

	void insertAtTheEnd(int data);

	void deleteFromTheFront(int data);

	void deleteFromTheMiddle(int data);

	void deleteFromTheEnd(int data);

	bool search(int data);

	void display();
};

