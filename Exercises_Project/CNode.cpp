#include "CNode.h"

CNode::CNode()
{
	nextNode = nullptr;
	data = -1;
}

void CNode::setData(int iData)
{
	data = iData;
}

int CNode::getData() const
{
	return (data);
}

void CNode::setNextNode(CNode* _nextNode)
{
	nextNode = _nextNode;
}

CNode* CNode::getNextNode() const
{
	return (nextNode);
}
