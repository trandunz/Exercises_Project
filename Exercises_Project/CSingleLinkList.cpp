#include <iostream>
#include "CSingleLinkList.h"

CSingleLinkList::CSingleLinkList()
{
	m_isStack = false;
	m_nNodeCount = 0;
	m_CfirstNode = nullptr;
}

CSingleLinkList::~CSingleLinkList()
{
	m_CfirstNode = nullptr;
	if (!m_isStack)
	{
		std::cout << "Destructing LinkList" << std::endl;
		while (m_nNodeCount > 0)
		{
			deleteFromTheEnd();
		}
	}
	
	
}

void CSingleLinkList::insertAtTheFront(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		m_CfirstNode = CNewNode;
		if (!m_isStack)
		{
			std::cout << "Inserted At Start (Frt::No Nodes Found)" << std::endl;
		}
		break;
	}
	default:
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		m_CfirstNode = CNewNode;
		if (!m_isStack)
		{
			std::cout << "Inserted at start (Frt::Node " << CNewNode->getData() << ")" << std::endl;
		}
		
		break;
	}
	
}

void CSingleLinkList::insertInTheMiddle(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		m_CfirstNode = CNewNode;
		if (!m_isStack)
		{
			std::cout << "Inserted At Start (Mid::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_nNodeCount++;
		CNode* CTemp = m_CfirstNode;
		for (int i = 0; i < (m_nNodeCount / 2) - 1; i++)
		{
			if (CTemp->getNextNode() != nullptr)
			{
				CTemp = CTemp->getNextNode();
			}
		}
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(CTemp->getNextNode());
		CTemp->setNextNode(CNewNode);

		CTemp = nullptr;
		if (!m_isStack)
		{
			std::cout << "Inserted At End (Mid::Only One Node)" << std::endl;
		}
		
		break;
	}
	default:
		m_nNodeCount++;
		CNode* CTemp = m_CfirstNode;
		for (int i = 0; i < (m_nNodeCount / 2) - 1; i++)
		{
			if (CTemp->getNextNode() != nullptr)
			{
				CTemp = CTemp->getNextNode();
			}
		}
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(CTemp->getNextNode());
		CTemp->setNextNode(CNewNode);

		CTemp = nullptr;
		if (!m_isStack)
		{
			std::cout << "Inserted In The Middle (Mid::Node " << CNewNode->getData() << ")" << std::endl;
		}
		
		break;
	}
	
}

void CSingleLinkList::insertAtTheEnd(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		m_CfirstNode = CNewNode;
		if (!m_isStack)
		{
			std::cout << "Inserted At Start (End::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	default:
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
		if (!m_isStack)
		{
			std::cout << "Inserted At End (End::Node " << CNewNode->getData() << ")" << std::endl;
		}
		
		break;
	}
}

void CSingleLinkList::deleteFromTheFront()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		if (!m_isStack)
		{
			std::cout << "(Frt::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_CfirstNode->setNextNode(nullptr);
		delete m_CfirstNode;
		m_CfirstNode = nullptr;
		if (!m_isStack)
		{
			std::cout << "Deleted First Node (Frt::Only One Node)" << std::endl;
		}
		
		m_nNodeCount--;
		break;
	}
	default:
		CNode* CTemp = m_CfirstNode;
		CNode* CSuperTemp = m_CfirstNode;
		CTemp = CTemp->getNextNode();
		m_CfirstNode = CTemp;
		CSuperTemp->setNextNode(nullptr);
		if (!m_isStack)
		{
			std::cout << "Deleted First Node (Frt::Node " << CSuperTemp->getData() << ")" << std::endl;
		}
		
		delete CSuperTemp;
		CSuperTemp = nullptr;
		CTemp = nullptr;
		m_nNodeCount--;
		break;
	}
	
}

void CSingleLinkList::deleteFromTheMiddle(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		if (!m_isStack)
		{
			std::cout << "(Mid::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_CfirstNode->setNextNode(nullptr);
		delete m_CfirstNode;
		m_CfirstNode = nullptr;
		if (!m_isStack)
		{
			std::cout << "Deleted Node (" << _data << ") (Del::Only One Node)" << std::endl;
		}

		m_nNodeCount--;
		break;
	}
	case 2:
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
		if (!m_isStack)
		{
			std::cout << "Deleted End Node (Mid::Only Two Nodes)" << std::endl;
		}
		
		m_nNodeCount--;
		break;
	}
	default:
		m_nNodeCount--;
		m_CfirstNode->setNextNode(m_CfirstNode->getNextNode()->getNextNode());
		CNode* CTemp = m_CfirstNode;
		for (int i = 0; i < (m_nNodeCount / 2) - 1; i++)
		{
			if (CTemp->getNextNode() != nullptr)
			{
				CTemp = CTemp->getNextNode();
			}
		}
		CTemp->setNextNode(nullptr);
		if (!m_isStack)
		{
			std::cout << "Deleted Middle Node (Mid::Node " << CTemp->getData() << ")" << std::endl;
		}
		
		delete CTemp;
		CTemp = nullptr;
		break;
	}
}

void CSingleLinkList::deleteFromTheEnd()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		if (!m_isStack)
		{
			std::cout << "(End::No Nodes Found)" << std::endl;
		}
		
		break;
	}
	case 1:
	{
		m_CfirstNode->setNextNode(nullptr);
		delete m_CfirstNode;
		m_CfirstNode = nullptr;
		if (!m_isStack)
		{
			std::cout << "Deleted First Node (End::Only One Node)" << std::endl;
		}
		
		m_nNodeCount--;
		break;
	}
	default:
		CNode* CTemp = m_CfirstNode;

		while (CTemp->getNextNode()->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();
		}
		CNode* CBeforeDelete = CTemp;
		CTemp = CBeforeDelete->getNextNode();
		if (!m_isStack)
		{
			std::cout << "Deleted End Node (End::Node " << CTemp->getData() << ")" << std::endl;
		}
		
		delete CTemp;

		CBeforeDelete->setNextNode(nullptr);
		CBeforeDelete = nullptr;
		CTemp = nullptr;

		
		m_nNodeCount--;
		break;
	}
	
}

void CSingleLinkList::Delete(int _data)
{
	if (search(_data))
	{
		CNode* CTemp = m_CfirstNode;

		switch (m_nNodeCount)
		{
		case 1:
		{
			m_CfirstNode->setNextNode(nullptr);
			delete m_CfirstNode;
			m_CfirstNode = nullptr;
			if (!m_isStack)
			{
				std::cout << "Deleted Node (" << _data << ") (Del::Only One Node)" << std::endl;
			}
			
			m_nNodeCount--;
			break;
		}
		default:
		{
			if (CTemp->getData() == _data)
			{
				m_CfirstNode = CTemp->getNextNode();
				CTemp->setNextNode(nullptr);
				delete CTemp;
				CTemp = nullptr;
				if (!m_isStack)
				{
					std::cout << "Deleted Node (" << _data << ")" << std::endl;
				}
				
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
				if (!m_isStack)
				{
					std::cout << "Deleted Node (" << _data << ")" << std::endl;
				}
				
				m_nNodeCount--;
			}
		}
			break;
		}
		

		
	}
}

bool CSingleLinkList::search(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		if (!m_isStack)
		{
			std::cout << "Search Failed (Sch::No Nodes Found)" << std::endl;
		}
		
		return (false);
		break;
	}
	default:
	{
		CNode* CTemp = m_CfirstNode;
		while (CTemp->getData() != _data && CTemp->getNextNode() != nullptr)
		{
			CTemp = CTemp->getNextNode();
		}

		if (CTemp->getData() == _data)
		{
			if (!m_isStack)
			{
				std::cout << "Search Successful (Sch::Found Node " << _data << ")" << std::endl;
			}
			
			CTemp = nullptr;
			return(true);

		}
		else
		{
			if (!m_isStack)
			{
				std::cout << "Search Failed (No Node With Matching Data (" << CTemp->getData() << "))" << std::endl;
			}
			
			CTemp = nullptr;
			return(false);
		}
	}
		break;
	}
}

void CSingleLinkList::display()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		std::cout << "Display Failed (Dis::No Nodes Found)" << std::endl;
	}
	default:
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
		std::cout << "Display Successful" << std::endl;
	}
	}
	
}
