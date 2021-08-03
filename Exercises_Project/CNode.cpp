#include <iostream>
#include "CNode.h"


CNode::CNode()
{
	m_CPrevNode = nullptr;
	m_CNextNode = nullptr;
	m_nData = -1;
}

//CNode::CNode(CNode* _firstNode)
//{
//	m_CNextNode = nullptr;
//	m_nData = -1;
//	m_CfirstNode = _firstNode;
//}

CNode::~CNode()
{
	
	m_CPrevNode = nullptr;
	m_CNextNode = nullptr;
	std::cout << "Destructing Node (" << m_nData << ")" << std::endl;
	m_nData = -1;
	delete m_CNextNode;
	delete m_CPrevNode;
}

void CNode::setData(int iData)
{
	m_nData = iData;
}

int CNode::getData() const
{
	return (m_nData);
}

void CNode::setNextNode(CNode* _nextNode)
{
	m_CNextNode = _nextNode;
}

void CNode::setPrevNode(CNode* _prevNode)
{
	m_CPrevNode = _prevNode;
}

CNode* CNode::getNextNode() const
{
	return (m_CNextNode);
}
