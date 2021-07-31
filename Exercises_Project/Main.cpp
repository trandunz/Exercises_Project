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
		CMatrix4* Matrix = new CMatrix4(3,3);
		CMatrix4* Matrix2 = new CMatrix4(4, 4);
		CMatrix4* Matrix3 = new CMatrix4(4, 4);
		Matrix->Start();
		Matrix->SetElement(1, 1, 1);
		Matrix->SetElement(1, 2, 2);
		Matrix->SetElement(1, 3, 3);
		Matrix->SetElement(2, 1, 4);
		Matrix->SetElement(2, 2, 5);
		Matrix->SetElement(2, 3, 6);
		Matrix->SetElement(3, 1, 7);
		Matrix->SetElement(3, 2, 8);
		Matrix->SetElement(3, 3, 9);

		CMatrix4::Det(Matrix);
		Matrix->DisplayMatrix();
		CMatrix4::Transpose(Matrix);
		Matrix->DisplayMatrix();
		Matrix2->Start();
		CMatrix4::Zero(Matrix2);
		CMatrix4::Identity(Matrix2);
		Matrix2->DisplayMatrix();
		Matrix3->Start();
		Matrix3->SetElement(2, 1, 3);
		Matrix3->DisplayMatrix();
		CMatrix4::Equals(Matrix, Matrix3);
		CMatrix4::Multiply(Matrix, Matrix3);
		Matrix->DisplayMatrix();
		
		
		break;
	}

	default:
	{
		break;
	}

	}

	return 0;
}