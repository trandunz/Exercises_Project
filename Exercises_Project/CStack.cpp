#include "CStack.h"
#include <iostream>

CStack::CStack()
{
    m_isStack = true;
}

CStack::~CStack()
{
    std::cout << "Destructing Stack" << std::endl;
    while (m_nNodeCount > 0 && m_CfirstNode != nullptr)
    {
        Pop();
    }
}

void CStack::Push(int _iData)
{
    
    insertAtTheFront(_iData);
    std::cout << "Pushed (Frt::Node " << _iData << ")" << std::endl;
}

void CStack::Pop(int _iData)
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Pop Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        while (m_CfirstNode->getData() != _iData)
        {
            std::cout << "Force Pop'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
            deleteFromTheFront();
            
        }
        std::cout << "Pop'd (Frt::Node " << _iData << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
    
}

void CStack::Pop()
{
    switch (m_nNodeCount)
    {
    case 0:
    {
        std::cout << "Pop Failed (Frt::No Nodes Found)" << std::endl;
        break;
    }
    default:
    {
        std::cout << "Pop'd (Frt::Node " << m_CfirstNode->getData() << ")" << std::endl;
        deleteFromTheFront();
        break;
    }
    }
}

void CStack::Peek()
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

bool CStack::IsEmpty()
{
    if (m_nNodeCount == 0)
    {
        return true;
    }
    return false;
}
