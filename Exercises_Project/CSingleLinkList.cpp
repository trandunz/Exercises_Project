#include <iostream>
#include "CSingleLinkList.h"

CSingleLinkList::CSingleLinkList()
{
	m_nNodeCount = 0;
	m_CfirstNode = nullptr;
}

CSingleLinkList::~CSingleLinkList()
{
	m_nNodeCount = 0;
	m_CfirstNode = nullptr;
	std::cout << "Destructing LinkList" << std::endl;
}

void CSingleLinkList::insertAtTheFront(int _data)
{
	m_nNodeCount++;

	CNode* CNewNode = new CNode;
	CNewNode->setNextNode(m_CfirstNode);
	CNewNode->setData(_data);
	m_CfirstNode = CNewNode;
	std::cout << "Inserted at start" << std::endl;
}

void CSingleLinkList::insertInTheMiddle(int _data, int _position)
{
	CNode* CTemp = m_CfirstNode;
	for (int i = 0; i < m_nNodeCount; i++)
	{
		std::cout << CTemp->getData() << std::endl;
		if (CTemp->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();
		}
	}
	CTemp = nullptr;
}

void CSingleLinkList::insertAtTheEnd(int _data)
{
	if (m_nNodeCount == 0)
	{
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		m_CfirstNode = CNewNode;
		std::cout << "Inserted at start" << std::endl;
	}
	else
	{
		m_nNodeCount++;

		CNode* CNewNode = new CNode;
		CNewNode->setData(_data);
		CNode* CTemp = m_CfirstNode;

		while (CTemp->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();

		}
		CTemp->setNextNode(CNewNode);
		CTemp = nullptr;
		std::cout << "Inserted at end" << std::endl;
	}
}

void CSingleLinkList::deleteFromTheFront()
{
	CNode* CTemp = m_CfirstNode;
	CNode* CSuperTemp = CTemp;
	CTemp = CTemp->getNextNode();
	m_CfirstNode = CTemp;
	CSuperTemp->setNextNode(nullptr);
	delete CSuperTemp;
	CSuperTemp = nullptr;
	CTemp = nullptr;
	std::cout << "Deleted First Node" << std::endl;
	m_nNodeCount--;
}

void CSingleLinkList::deleteFromTheMiddle(int _data)
{
}

void CSingleLinkList::deleteFromTheEnd()
{
	CNode* CTemp = m_CfirstNode;

	while (CTemp->getNextNode()->getNextNode() != nullptr)
	{
		CTemp = CTemp->getNextNode();
	}
	CNode* CBeforeDelete = CTemp;

	CTemp = CBeforeDelete->getNextNode();
	delete CTemp;
	

	CBeforeDelete->setNextNode(nullptr);
	CBeforeDelete = nullptr;
	CTemp = nullptr;

	std::cout << "Deleted End Node" << std::endl;
	m_nNodeCount--;
}

void CSingleLinkList::Delete(int _data)
{
	if (search(_data))
	{
		CNode* CTemp = m_CfirstNode;

		if (CTemp->getData() == _data)
		{
			m_CfirstNode = CTemp->getNextNode();
			CTemp->setNextNode(nullptr);
			delete CTemp;
			CTemp = nullptr;

			std::cout << "Deleted Node (" << _data << ")" << std::endl;
			m_nNodeCount--;
		}
		else
		{
			while (CTemp->getNextNode()->getData() != _data && CTemp->getNextNode() != nullptr)
			{
				CTemp = CTemp->getNextNode();
			}
			CNode* CBeforeDelete = CTemp;

			CTemp = CTemp->getNextNode()->getNextNode();

			CBeforeDelete->getNextNode()->setNextNode(nullptr);
			delete CBeforeDelete->getNextNode();

			CBeforeDelete->setNextNode(CTemp);

			CBeforeDelete = nullptr;
			CTemp = nullptr;

			std::cout << "Deleted Node (" << _data << ")" << std::endl;
			m_nNodeCount--;
		}

		
	}
	
}

bool CSingleLinkList::search(int _data)
{
	CNode* CTemp = m_CfirstNode;
	while (CTemp->getData() != _data && CTemp->getNextNode() != nullptr)
	{
		CTemp = CTemp->getNextNode();
	}

	if (CTemp->getData() == _data)
	{
		std::cout << "Search Successful" << std::endl;
		return(true);
		
	}
	else
	{
		std::cout << "Search Failed (No Node With Matching Data (" << CTemp->getData() <<  "))" << std::endl;
		return(false);
	}
}

void CSingleLinkList::display()
{
	CNode* CTemp = m_CfirstNode;
	for (int i = 0 ; i < m_nNodeCount; i++)
	{
		std::cout << CTemp->getData() << std::endl;
		if (CTemp->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();
		}
	}
	CTemp = nullptr;
}
