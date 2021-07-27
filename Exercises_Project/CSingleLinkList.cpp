#include "CSingleLinkList.h"

CSingleLinkList::CSingleLinkList()
{
	firstNode = nullptr;
}

CSingleLinkList::~CSingleLinkList()
{

}

void CSingleLinkList::insertAtTheFront(int data)
{
	CNode* newNode = new CNode;
	newNode->setNextNode(firstNode);
	firstNode = newNode;
	newNode->setData(data);
}

void CSingleLinkList::insertInTheMiddle(int data, int position)
{
}

void CSingleLinkList::insertAtTheEnd(int data)
{
	CNode* newNode = new CNode;
	newNode->setData(data);
	newNode->setNextNode(firstNode);
	CNode* temp = firstNode;
	while(temp->getNextNode() != nullptr)
	{
		temp = temp->getNextNode();
	}
}

void CSingleLinkList::deleteFromTheFront(int data)
{
}

void CSingleLinkList::deleteFromTheMiddle(int data)
{
}

void CSingleLinkList::deleteFromTheEnd(int data)
{
}

bool CSingleLinkList::search(int data)
{
	return false;
}

void CSingleLinkList::display()
{
}
