#pragma once
#ifndef _SINGLE_LINKEDLIST_H__
#define _SINGLE_LINKEDLIST_H__

#include "CNode.h"

class CSingleLinkList
{
protected:
	bool m_isStack;
	CNode* m_CfirstNode;
	int m_nNodeCount;

public:
	CSingleLinkList();

	virtual ~CSingleLinkList();

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

#endif