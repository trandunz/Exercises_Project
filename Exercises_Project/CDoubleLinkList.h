#pragma once
#include "CNode.h"
#include <iostream>
class CDoubleLinkList
{
private:
	CNode* m_CfirstNode;
	int m_nNodeCount;

public:
	CDoubleLinkList();

	~CDoubleLinkList();

	void insertAtTheFront(int _data);

	void insertInTheMiddle(int _data);

	void insertAtTheEnd(int _data);

	void deleteFromTheFront();

	void deleteFromTheMiddle(int _data);

	void deleteFromTheEnd();

	void Delete(int _data);

	bool search(int _data);

	void display();
};

