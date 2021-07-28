#pragma once
#ifndef _SINGLE_LINKEDLIST_H__
#define _SINGLE_LINKEDLIST_H__

#include "CNode.h"

class CSingleLinkList
{
private:
	CNode* m_CfirstNode;
	int m_nNodeCount;

public:
	CSingleLinkList();

	~CSingleLinkList();

	void insertAtTheFront(int _data);

	void insertInTheMiddle(int _data, int _position);

	void insertAtTheEnd(int _data);

	void deleteFromTheFront();

	void deleteFromTheMiddle(int _data);

	void deleteFromTheEnd();

	void Delete(int _data);

	bool search(int _data);

	void display();

};

#endif