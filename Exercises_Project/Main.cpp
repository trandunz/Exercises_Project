#include "CSingleLinkList.h"
#include "CMatrix4.h"
#include "CStack.h"
#include "CQueue.h"
#include "CSort.h"
#include <iostream>
#include"conio.h"
#include"BubbleSort.h"

enum RUNTYPE
{
	SINGLELINKLIST,
	DOUBLELINKLIST,
	STACK,
	QUEUE,
	MATRIX4,
	QUICKSORT,
	BUBBLESORT,
	INSERTSORT,
	SELECTIONSORT,
	RADIXSORT,
};

RUNTYPE m_eRunType = RUNTYPE::SELECTIONSORT;

int main()
{
	switch (m_eRunType)
	{
	case SINGLELINKLIST:
	{
		CSingleLinkList* newLinkList = new CSingleLinkList;

		newLinkList->insertAtTheFront(2);
		newLinkList->insertAtTheFront(1);
		newLinkList->insertAtTheEnd(3);
		newLinkList->insertAtTheEnd(4);
		newLinkList->display();
		newLinkList->deleteFromTheEnd();
		newLinkList->display();
		newLinkList->deleteFromTheFront();
		newLinkList->display();
		newLinkList->search(2);
		newLinkList->search(4);
		newLinkList->display();

		delete newLinkList;
		newLinkList = nullptr;

		break;
	}

	case MATRIX4:
	{
		CMatrix4* MatrixA = new CMatrix4;
		CMatrix4* MatrixB = new CMatrix4;
		CMatrix4* Result = new CMatrix4;
		
		MatrixA->SetElement(1, 1, 8);
		MatrixA->SetElement(2, 2, 7);
		MatrixA->SetElement(3, 3, 6);
		MatrixA->SetElement(4, 4, 5);

		/*CMatrix4::Multiply(*MatrixA, *MatrixB, *Result);*/
		CMatrix4::PrintMatrix(*MatrixA);
		CMatrix4::Determinant(*MatrixA);
		
		delete MatrixA;
		delete MatrixB;
		delete Result;
		MatrixA = nullptr;
		MatrixB = nullptr;
		Result = nullptr;
		break;
	}

	case DOUBLELINKLIST:
	{

	}

	case STACK:
	{
		CStack* newStack = new CStack;

		newStack->Push(1);
		newStack->Push(5);
		newStack->Push(4);
		newStack->Push(3);
		newStack->Push(2);
		newStack->Pop(4);
		newStack->Peek();

		delete newStack;
		newStack = nullptr;

	}

	case QUEUE:
	{
		CQueue* newQueue = new CQueue;
		newQueue->Enqueue(1);
		newQueue->Enqueue(5);
		newQueue->Enqueue(4);
		newQueue->Enqueue(3);
		newQueue->Enqueue(2);
		newQueue->Dequeue(4);
		newQueue->Peek();
		delete newQueue;
		newQueue = nullptr;
	}

	case QUICKSORT:
	{
		/*int Array[8] = { 8,0,7,5,4,3,6,2 };
		for (int i = 0; i < 8; i++)
		{
			std::cout << Array[i] << std::endl;
		}*/
		CSort* QuickSort = new CSort(8);
		QuickSort->QuickSort();

		/*delete[] Array;*/
		delete QuickSort;
		/*Array = nullptr;*/
		QuickSort = nullptr;
		break;
	}

	case BUBBLESORT:
	{
		std::cout << "Bubble Sort Algorithm" << std::endl;
		std::cout << "**********************" << std::endl << std::endl;
		BubbleSortAlgo<int> array(5);
		array.push(80);
		array.push(64);
		array.push(99);
		array.push(76);
		array.push(5);

		std::cout << "Before sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl;

		array.BubbleSort();

		std::cout << "After sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl << std::endl;

		_getch();
		break;
	}
	case INSERTSORT:
	{
		std::cout << "Insertion Sort Algorithm" << std::endl;
		std::cout << "**********************" << std::endl << std::endl;
		BubbleSortAlgo<int> array(5);
		array.push(80);
		array.push(64);
		array.push(99);
		array.push(76);
		array.push(5);

		std::cout << "Before sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl;

		array.InsertSort();

		std::cout << "After sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl << std::endl;

		_getch();
		break;
	}
	case SELECTIONSORT:
	{
		std::cout << "Selection Sort Algorithm" << std::endl;
		std::cout << "**********************" << std::endl << std::endl;
		BubbleSortAlgo<int> array(5);
		array.push(80);
		array.push(64);
		array.push(99);
		array.push(76);
		array.push(5);

		std::cout << "Before sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl;

		array.SelectionSort();

		std::cout << "After sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl << std::endl;

		_getch();
		break;
	}
	/*case RADIXSORT:
	{
		std::cout << "Radix Sort Algorithm" << std::endl;
		std::cout << "**********************" << std::endl << std::endl;
		BubbleSortAlgo<int> array(5);
		array.push(80);
		array.push(64);
		array.push(99);
		array.push(76);
		array.push(5);

		std::cout << "Before sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl;

		array.radixsort();

		std::cout << "After sort:";
		for (int i = 0; i < 5; i++)
		{
			std::cout << " " << array[i];
		}
		std::cout << std::endl << std::endl;

		_getch();
		break;
	}*/
	default:
	{
		break;
	}
	}

	return 0;
}
