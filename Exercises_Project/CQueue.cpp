#include "CQueue.h"
#include <iostream>

CQueue::CQueue()
{
    m_isStack = true;
    
}

CQueue::~CQueue()
{
    std::cout << "Destructing Queue" << std::endl;
    while (m_nNodeCount > 0 && m_CfirstNode != nullptr)
    {
        Dequeue();
    }
}

void CQueue::Enqueue(int _iData)
{
    insertAtTheEnd(_iData);
    std::cout << "Enqueue'd (Frt::Node " << _iData << ")" << std::endl;
}

void CQueue::Enqueue_Back(int _iData)
{
    insertAtTheEnd(_iData);
    std::cout << "Enqueue'd From Back (Frt::Node " << _iData << ")" << std::endl;
}

void CQueue::Enqueue_Front(int _iData)
{
    insertAtTheFront(_iData);
    std::cout << "Enqueue'd From Front (Frt::Node " << _iData << ")" << std::endl;
}

void CQueue::Dequeue(int _iData)
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        while (m_CfirstNode->getData() != _iData)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd (Frt::Node " << _iData << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CQueue::Dequeue()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CQueue::Dequeue_Back(int _iData)
{
    
}

void CQueue::Dequeue_Back()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd From Back (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheEnd();
        break;
    }
    }
}

void CQueue::Dequeue_Front(int _iData)
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        while (m_CfirstNode->getData() != _iData)
        {
            std::cout << "Force Dequeue'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
            deleteFromTheFront();

        }
        std::cout << "Dequeue'd From Front (Frt::Node " << _iData << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CQueue::Dequeue_Front()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Dequeue Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Dequeue'd From Front (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CQueue::Peek()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Peak Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Peak Success (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        break;
    }
    }
}

void CQueue::Peek_Front()
{
}

void CQueue::Peek_Back()
{
}

bool CQueue::IsEmpty()
{
    if (m_nNodeCount == 0)
    {
        return true;
    }
	return false;
}
