#include "CSort.h"

CSort::CSort(int _arraysize)
{
	SetSize(_arraysize);
	m_iArray = new int[m_iSize] { 8, 0, 7, 5, 4, 3, 6, 2 };
}

CSort::~CSort()
{
	delete[] m_iArray;
	m_iArray = nullptr;
}

void CSort::BubbleSort(int& _arr)
{
}

void CSort::QuickSort()
{
	int PivotIndex;
	PivotIndex = m_iSize / 2;
	Swap(0, PivotIndex);

	int UpCount = 0;
	int DownCount = 0;
	while (!IndexGreaterThan(UpCount, DownCount))
	{
		for (int i = 0; i < m_iSize; i++)
		{
			if (m_iArray[0] < m_iArray[i])
			{
				UpCount = i;
				break;
			}
		}
		for (int i = (m_iSize - 1); i > 0; i--)
		{
			if (m_iArray[0] > m_iArray[i])
			{
				DownCount = i;
				break;
			}
		}
		Swap(UpCount, DownCount);
	}
	Swap(0, DownCount);
	Display();
}

void CSort::SetSize(int _value)
{
	m_iSize = _value;
}

int CSort::GetSize()
{
	return m_iSize;
}

void CSort::Swap(int index1, int index2)
{
	int Temp = m_iArray[0];
	m_iArray[0] = m_iArray[index2];
	m_iArray[index2] = Temp;
}

bool CSort::IndexGreaterThan(int index1, int index2)
{
	if (index1 > index2)
	{
		return true;
	}
	return false;
}

void CSort::Display()
{
	for (int i = 0; i < m_iSize; i++)
	{
		std::cout << m_iArray[i] << std::endl;
	}
}
