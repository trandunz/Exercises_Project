#include "CDoubleLinkList.h"

CDoubleLinkList::CDoubleLinkList()
{
    m_nNodeCount = 0;
    m_CfirstNode = nullptr;
}

CDoubleLinkList::~CDoubleLinkList()
{
    m_nNodeCount = 0;
    m_CfirstNode = nullptr;
    std::cout << "Destructing LinkList" << std::endl;
}

void CDoubleLinkList::insertAtTheFront(int _data)
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
		std::cout << "Inserted At Start (Frt::No Nodes Found)" << std::endl;
	}
	default:
		m_nNodeCount++;
		CNode* CNewNode = new CNode;
		CNewNode->setNextNode(m_CfirstNode);
		CNewNode->setData(_data);
		CNewNode->getNextNode()->setPrevNode(CNewNode);
		m_CfirstNode = CNewNode;
		std::cout << "Inserted at start (Frt::Node " << CNewNode->getData() << ")" << std::endl;
		break;
	}
}

void CDoubleLinkList::insertInTheMiddle(int _data)
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
		std::cout << "Inserted At Start (Mid::No Nodes Found)" << std::endl;
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
		CNewNode->setPrevNode(CTemp);
		CTemp = nullptr;
		std::cout << "Inserted At End (Mid::Only One Node)" << std::endl;
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
		CTemp->getNextNode()->setPrevNode(CNewNode);
		CTemp->setNextNode(CNewNode);
		CNewNode->setPrevNode(CTemp);
		CTemp = nullptr;
		std::cout << "Inserted In The Middle (Mid::Node " << CNewNode->getData() << ")" << std::endl;
		break;
	}
}

void CDoubleLinkList::insertAtTheEnd(int _data)
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
		std::cout << "Inserted At Start (End::No Nodes Found)" << std::endl;
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
		CNewNode->setPrevNode(CTemp);
		CTemp = nullptr;
		std::cout << "Inserted At End (End::Node " << CNewNode->getData() << ")" << std::endl;
		break;
	}
}

void CDoubleLinkList::deleteFromTheFront()
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		std::cout << "(Frt::No Nodes Found)" << std::endl;
		break;
	}
	case 1:
	{
		m_CfirstNode->setNextNode(nullptr);
		m_CfirstNode->setPrevNode(nullptr);
		delete m_CfirstNode;
		m_CfirstNode = nullptr;
		std::cout << "Deleted First Node (Frt::Only One Node)" << std::endl;
		m_nNodeCount--;
		break;
	}
	default:
		CNode* CTemp = m_CfirstNode;
		CNode* CSuperTemp = CTemp;
		CTemp = CTemp->getNextNode();
		CTemp->setPrevNode(nullptr);
		m_CfirstNode = CTemp;
		CSuperTemp->setNextNode(nullptr);
		std::cout << "Deleted First Node (Frt::Node " << CSuperTemp->getData() << ")" << std::endl;
		delete CSuperTemp;
		CSuperTemp = nullptr;
		CTemp = nullptr;
		m_nNodeCount--;
		break;
	}
}

void CDoubleLinkList::deleteFromTheMiddle(int _data)
{
}

void CDoubleLinkList::deleteFromTheEnd()
{
}

void CDoubleLinkList::Delete(int _data)
{

}

bool CDoubleLinkList::search(int _data)
{
	switch (m_nNodeCount)
	{
	case 0:
	{
		std::cout << "Search Failed (Sch::No Nodes Found)" << std::endl;
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
			std::cout << "Search Successful (Sch::Found Node " << _data << ")" << std::endl;
			CTemp = nullptr;
			return(true);

		}
		else
		{
			std::cout << "Search Failed (No Node With Matching Data (" << CTemp->getData() << "))" << std::endl;
			CTemp = nullptr;
			return(false);
		}
	}
	break;
	}
}

void CDoubleLinkList::display()
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
