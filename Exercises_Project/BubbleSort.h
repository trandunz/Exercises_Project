#pragma once
#include<cassert>
#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H
template<typename T>
class BubbleSortAlgo
{
public:
	BubbleSortAlgo(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0),
		m_growSize(0), m_numElements(0)
	{
		if (size)
		{
			m_maxSize = size;
			m_array = new T[m_maxSize];
			memset(m_array, 0, sizeof(T) * m_maxSize);
			m_growSize = ((growBy > 0) ? growBy : 0);
		}
	}
	~BubbleSortAlgo()
	{
		if (m_array != NULL)
		{
			delete[] m_array;
			m_array = NULL;
		}
	}
	void push(T val)
	{
		assert(m_array != NULL);
		if (m_numElements >= m_maxSize)
		{
			Expand();
		}
		m_array[m_numElements] = val;
		m_numElements++;
	}
	void pop()
	{
		if (m_numElements > 0)
			m_numElements--;
	}
	void remove(int index)
	{
		assert(m_array != NULL);
		if (index >= m_maxSize)
		{
			return;
		}
		for (int k = index; k < m_maxSize - 1; k++)
			m_array[k] = m_array[k + 1];
		m_maxSize--;
		if (m_numElements >= m_maxSize)
			m_numElements = m_maxSize - 1;
	}
	T& operator[](int index)
	{
		assert(m_array != NULL && index <= m_numElements);
		return m_array[index];
	}
	T search(T val)
	{
		assert(m_array != NULL);
		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}
		return -1;
	}
	T getMax()
	{
		T max = m_array[0];
		for (int i = 1; i < m_numElements; i++)
			if (m_array[i] > max)
				max = m_array[i];
		return max;
	}
	int getMinIndex()
	{
		int i;
		T min = m_array[0];
		int minindex = 0;
		for (i = 1; i < m_numElements; i++)
		{
			if (m_array[i] > min)
			{
				min = m_array[i];
				minindex = i;
			}
				
		}
			
		return minindex;
	}
	inline void swap(T* _v1, T* _v2)
	{
		T temp = *_v1;
		*_v1 = *_v2;
		*_v2 = temp;
	}
	void BubbleSort()
	{
		assert(m_array != NULL);
		for (int k = m_numElements - 1; k > 0; k--)
		{
			for (int i = 0; i < k; i++)
			{
				if (m_array[i] > m_array[i + 1])
				{
					T temp = m_array[i];
					m_array[i] = m_array[i + 1];
					m_array[i + 1] = temp;
				}
			}
		}
	}
	inline void InsertSort()
	{
		assert(m_array != NULL);
		int i, j;
		for (i = 1; i < m_numElements; i++)
		{
			T temp = m_array[i];
			j = i - 1;

			/* Move elements of m_array[0..i-1], that are
			greater than temp, to one position ahead
			of their current position */
			while (j >= 0 && m_array[j] > temp)
			{
				m_array[j + 1] = m_array[j];
				j = j - 1;
			}
			m_array[j + 1] = temp;
		}
	}

	inline void SelectionSort()
	{
		assert(m_array != NULL);
		int i, j;
		int min_index;

		// One by one move boundary of unsorted subarray
		for (i = 0; i < m_numElements - 1; i++)
		{
			// Find the minimum element in unsorted array
			min_index = i;
			for (j = i + 1; j < m_numElements; j++)
				if (m_array[j] < m_array[min_index])
					min_index = j;

			// Swap the found minimum element with the first element
			swap(&m_array[min_index], &m_array[i]);
		}
	}

	//inline void countSort(int exp)
	//{
	//	assert(m_array != NULL);
	//	T output(m_numElements); // output array
	//	int i;
	//	int count[10] = {};

	//	// Store count of occurrences in count[]
	//	for (i = 0; i < m_numElements; i++)
	//	{
	//		count[(m_array[i] / exp) % 10]++;
	//	}
	//		
	//	// Change count[i] so that count[i] now contains actual
	//	//  position of this digit in output[]
	//	for (i = 1; i < 10; i++)
	//	{
	//		count[i] += count[i - 1];
	//	}
	//		
	//	// Build the output array
	//	for (i = m_numElements - 1; i >= 0; i--)
	//	{
	//		output[count[(m_array[i] / exp) % 10] - 1] = m_array[i];
	//		count[(m_array[i] / exp) % 10]--;
	//	}

	//	// Copy the output array to m_array[], so that m_array[] now
	//	// contains sorted numbers according to current digit
	//	for (i = 0; i < m_numElements; i++)
	//	{
	//		m_array[i] = output[i];
	//	}
	//		
	//}  // broken
	//inline void radixsort()
	//{
	//	assert(m_array != NULL);
	//	// Find the maximum number to know number of digits
	//	T m = getMax();

	//	// Do counting sort for every digit. Note that instead
	//	// of passing digit number, exp is passed. exp is 10^i
	//	// where i is current digit number
	//	for (int exp = 1; m / exp > 0; exp *= 10)
	//	{
	//		countSort(exp);
	//	}
	//}
	void clear() { m_numElements = 0; }
	int GetSize() { return m_numElements; }
	int GetMaxSize() { return m_maxSize; }
	int GetGrowSize() { return m_growSize; }
	void SetGrowSize(int val)
	{
		assert(val >= 0);
		m_growSize = val;
	}
private:
	bool Expand()
	{
		if (m_growSize <= 0)
			return false;
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != NULL);
		memcpy(temp, m_array, sizeof(T) * m_maxSize);
		delete[] m_array;
		m_array = temp;
		m_maxSize += m_growSize;
		return true;
	}
private:
	T* m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;
};
#endif 


