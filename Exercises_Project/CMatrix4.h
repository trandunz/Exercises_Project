#pragma once
#include <iostream>
#include <math.h>

class CMatrix4
{
public:
	float m_fMatrix[4][4];
	float m_PMatrix[4][4] = { {1,0,0,0},
							  {0,1,0,0},
							  {0,0,1,0},
							  {0,0,1,0} };

	float m_TMatrix[4][4] = { {1,0,0,1},
							  {0,1,0,1},
							  {0,0,1,1},
							  {0,0,0,1} };

	float m_RMatrix[4][4] = { {1,0,0,0},
							  {0,1,0,0},
							  {0,0,1,0},
							  {0,0,0,1} };
	CMatrix4();
	~CMatrix4();

	CMatrix4& Identity(CMatrix4& _rResult);
	CMatrix4& Zero(CMatrix4& _rResult);

	bool Equals(const CMatrix4& _rA, const CMatrix4& _rB);

	CMatrix4& Add(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);
	CMatrix4& Subtract(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);

	CMatrix4& Multiply(float _fScalar, const CMatrix4& _rA, CMatrix4& _rResult);
	CMatrix4& Multiply(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult);

	CMatrix4& Transpose(const CMatrix4& _rA, CMatrix4& _rResult);
	
	void InitTMatrix(float _dX, float _dY, float _dZ);
	void InitRMatrix(float _dX, float _dY, float _dZ);
	void InitProjMatrix(float _distance);
	CMatrix4& Rot(const CMatrix4& _rA, CMatrix4& _rResult);
	CMatrix4& Trans(const CMatrix4& _rA, CMatrix4& _rResult);
	CMatrix4& Proj(const CMatrix4& _rA, CMatrix4& _rResult);

	float Determinant(const CMatrix4& _rA);

	bool Inverse(const CMatrix4& _rA, CMatrix4& _rResult);

	bool TestHarness();
	void PrintMatrix(CMatrix4& _rMatrix);
private:
	
	void SetZero();
};

