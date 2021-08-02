#include "CSingleLinkList.h"
#include "CMatrix4.h"
#include <iostream>

enum RUNTYPE
{
	LINKLIST,
	MATRIX4
};

RUNTYPE m_eRunType = RUNTYPE::MATRIX4;

int main()
{
	switch (m_eRunType)
	{
	case LINKLIST:
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

	default:
	{
		break;
	}

	}


	return 0;
}