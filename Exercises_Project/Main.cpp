#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include "CSingleLinkList.h"
#include "CMatrix4.h"
#include "CStack.h"
#include "CQueue.h"
#include "CSort.h"
#include"conio.h"
#include"BubbleSort.h"

using namespace std;

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
	STD_STACK,
	STD_QUEUE,
	STD_VECTOR_ITERATOR,
	STD_VECTOR_STRINGS
};

RUNTYPE m_eRunType = RUNTYPE::SELECTIONSORT;

string* ptrToElement(vector<string>* const pVec, int i);

int main()
{
	switch (m_eRunType)
	{
	case STD_STACK:
	{
		stack<int> myStack;
		for (int i = 1; i <= 10; ++i)
		{
			cout << "Pushing " << i << " onto the stack." << endl;
			myStack.push(i);
		}
		while (!myStack.empty())
		{
			cout << myStack.top() << " is at the top of the stack, ";
			cout << "Popping the stack..." << endl;
			myStack.pop();
		}
		cout << endl;
		int iTemp = 0;
		cin >> iTemp;

		break;
	}

	case STD_QUEUE:
	{
		queue<int> myQueue;
		for (int i = 1; i <= 10; ++i)
		{
			cout << "Enqueue " << i << " onto the queue." << endl;
			myQueue.push(i);
		}
		while (!myQueue.empty())
		{
			cout << myQueue.front() << " is at the front of the queue, ";
			cout << "Dequeue the front of the queue..." << endl;
			myQueue.pop();
		}
		cout << endl;
		int iTemp = 0;
		cin >> iTemp;

		break;
	}

	case STD_VECTOR_ITERATOR:
	{
		// Declare a string vector.
		vector<string> strPlayersVec;
		// Declare a string vector iterator.
		vector<string>::iterator myStringVecIterator;
		// Add some elements to the vector.
		strPlayersVec.push_back("Darius");
		strPlayersVec.push_back("David");
		strPlayersVec.push_back("Porter");
		strPlayersVec.push_back("Leon");
		strPlayersVec.push_back("Mark");
		strPlayersVec.push_back("Steffan");
		// This is the old way, which is similar to getting data
		// out of arrays.
		cout << endl << endl;
		cout << "C/C++ Style" << endl;
		cout << "-----------" << endl;
		for (unsigned int i = 0; i < strPlayersVec.size(); i++)
		{
			cout << strPlayersVec[i] << endl;
		}
		// Using the iterator.
		cout << endl << endl;
		cout << "STL Iterator Style" << endl;
		cout << "------------------" << endl;
		for (myStringVecIterator = strPlayersVec.begin();
			myStringVecIterator != strPlayersVec.end();
			myStringVecIterator++)
		{
			// Dereference the string vector iterator in a
			// similiar fashion to how we dereference a pointer.
			cout << *myStringVecIterator << endl;
		}
		int iTemp = 0;
		cin >> iTemp;

		break;
	}

	case STD_VECTOR_STRINGS:
	{
		// Declare a vector of strings.
		vector<string> vecInventory;
		// 'push_back' appends (Inserts) an element to the end of
		// a vector, allocating memory for it if necessary.
		vecInventory.push_back("sword");
		vecInventory.push_back("shield");
		vecInventory.push_back("armour");
		// Display string object that the returned pointer points to.
		cout << "Sending the object pointed to by returned pointer: " << endl;
		cout << *(ptrToElement(&vecInventory, 0)) << endl << endl;
		// Assign one pointer to another -- inexpensive assignment.
		cout << "Assigning the returned pointer to another pointer." << endl;
		string* pStr = ptrToElement(&vecInventory, 1);
		cout << "Sending the object pointed to by new pointer to cout.";
		cout << endl;
		cout << *pStr << endl << endl;
		// Copies a string, EXPENSIVE assignment.
		cout << "Assigning object pointed by pointer to a string object.";
		cout << endl;
		string str = *(ptrToElement(&vecInventory, 2));
		cout << "Sending the new string object to cout." << endl;
		cout << str << endl << endl;
		// Alter the string object through a returned pointer.
		cout << "Altering an object through a returned pointer." << endl;
		*pStr = "Healing Potion.";
		cout << "Sending the altered object to cout" << endl;
		cout << vecInventory[1] << endl;
		int iTemp = 0;
		cin >> iTemp;

		break;
	}

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

string* ptrToElement(vector<string>* const pVec, int i)
{
	// Returns the address of the string in position i of the vector
	// that pVec points to.
	return (&((*pVec)[i]));
}
