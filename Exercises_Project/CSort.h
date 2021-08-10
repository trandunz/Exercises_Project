#pragma once
#include <iostream>
class CSort
{
public:
	CSort(int _arraysize);
	~CSort();

	void BubbleSort(int& _arr);
	void QuickSort();
	
	void SetSize(int _value);
	int GetSize();

	void Swap(int value1, int value2);
	bool IndexGreaterThan(int index1, int index2);

	void Display();

private:
	int m_iSize;
	int* m_iArray;


};

