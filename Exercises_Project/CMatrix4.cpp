#include "CMatrix4.h"

CMatrix4::CMatrix4()
{
	float m_fMatrix[4][4] = {};
	SetZero();
}

CMatrix4::~CMatrix4()
{
}

CMatrix4& CMatrix4::Identity(CMatrix4& _rResult)
{
	// TODO: insert return statement here
	Zero(_rResult);

	for (int i = 0; i < 4; i++)
	{
		_rResult.m_fMatrix[i][i] = 1;
	}
	return _rResult;
}

CMatrix4& CMatrix4::Zero(CMatrix4& _rResult)
{
	// TODO: insert return statement here
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			_rResult.m_fMatrix[y][x] = 0;
		}
	}
	return _rResult;
}

bool CMatrix4::Equals(const CMatrix4& _rA, const CMatrix4& _rB)
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (_rA.m_fMatrix[y][x] != _rB.m_fMatrix[y][x])
			{
				return false;
			}
			
		}
	}
	return true;
}

CMatrix4& CMatrix4::Add(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult)
{
	// TODO: insert return statement here
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			_rResult.m_fMatrix[y][x] = _rA.m_fMatrix[y][x] + _rB.m_fMatrix[y][x];

		}
	}
	return _rResult;
}

CMatrix4& CMatrix4::Subtract(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult)
{
	// TODO: insert return statement here
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			_rResult.m_fMatrix[y][x] = _rA.m_fMatrix[y][x] - _rB.m_fMatrix[y][x];

		}
	}
	return _rResult;
}

CMatrix4& CMatrix4::Multiply(float _fScalar, const CMatrix4& _rA, CMatrix4& _rResult)
{
	// TODO: insert return statement here
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			_rResult.m_fMatrix[y][x] = _rA.m_fMatrix[y][x] * _fScalar;

		}
	}
	return _rResult;
}

CMatrix4& CMatrix4::Multiply(const CMatrix4& _rA, const CMatrix4& _rB, CMatrix4& _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				_rResult.m_fMatrix[i][j] += _rA.m_fMatrix[i][k] * _rB.m_fMatrix[k][j];
			}
		}
	}
	
	return _rResult;
}

CMatrix4& CMatrix4::Transpose(const CMatrix4& _rA, CMatrix4& _rResult)
{
	// TODO: insert return statement here
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j) 
		{
			_rResult.m_fMatrix[j][i] = _rA.m_fMatrix[i][j];
		}
	}
		
	return _rResult;
}

float CMatrix4::Determinant(const CMatrix4& _rA)
{
	float c, r = 1;
	CMatrix4 TempMatrix;
	for (int i = 0; i < 4; i++)
	{

		for (int k = i + 1; k < 4; k++) 
		{
			c = _rA.m_fMatrix[k][i] / _rA.m_fMatrix[i][i];

			for (int j = i; j < 4; j++)
			{
				TempMatrix.m_fMatrix[k][j] = _rA.m_fMatrix[k][j] - c * _rA.m_fMatrix[i][j];
			}
				
		}
	}
	for (int i = 0; i < 4; i++)
	{
		r *= _rA.m_fMatrix[i][i];
	}
		
	std::cout << r << std::endl;

	return r;
}

bool CMatrix4::Inverse(const CMatrix4& _rA, CMatrix4& _rResult)
{
	//
	// Inversion by Cramer's rule.  Code taken from an Intel publication
	//
	float Result[4][4] = {};
	float tmp[12]; /* temp array for pairs */
	float src[16]; /* array of transpose source matrix */
	float det; /* determinant */
	/* transpose matrix */
	for (int i = 0; i < 4; i++)
	{
		src[i + 0] = _rA.m_fMatrix[i][0];
		src[i + 4] = _rA.m_fMatrix[i][1];
		src[i + 8] = _rA.m_fMatrix[i][2];
		src[i + 12] = _rA.m_fMatrix[i][3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0] = src[10] * src[15];
	tmp[1] = src[11] * src[14];
	tmp[2] = src[9] * src[15];
	tmp[3] = src[11] * src[13];
	tmp[4] = src[9] * src[14];
	tmp[5] = src[10] * src[13];
	tmp[6] = src[8] * src[15];
	tmp[7] = src[11] * src[12];
	tmp[8] = src[8] * src[14];
	tmp[9] = src[10] * src[12];
	tmp[10] = src[8] * src[13];
	tmp[11] = src[9] * src[12];
	/* calculate first 8 elements (cofactors) */
	Result[0][0] = tmp[0] * src[5] + tmp[3] * src[6] + tmp[4] * src[7];
	Result[0][0] -= tmp[1] * src[5] + tmp[2] * src[6] + tmp[5] * src[7];
	Result[0][1] = tmp[1] * src[4] + tmp[6] * src[6] + tmp[9] * src[7];
	Result[0][1] -= tmp[0] * src[4] + tmp[7] * src[6] + tmp[8] * src[7];
	Result[0][2] = tmp[2] * src[4] + tmp[7] * src[5] + tmp[10] * src[7];
	Result[0][2] -= tmp[3] * src[4] + tmp[6] * src[5] + tmp[11] * src[7];
	Result[0][3] = tmp[5] * src[4] + tmp[8] * src[5] + tmp[11] * src[6];
	Result[0][3] -= tmp[4] * src[4] + tmp[9] * src[5] + tmp[10] * src[6];
	Result[1][0] = tmp[1] * src[1] + tmp[2] * src[2] + tmp[5] * src[3];
	Result[1][0] -= tmp[0] * src[1] + tmp[3] * src[2] + tmp[4] * src[3];
	Result[1][1] = tmp[0] * src[0] + tmp[7] * src[2] + tmp[8] * src[3];
	Result[1][1] -= tmp[1] * src[0] + tmp[6] * src[2] + tmp[9] * src[3];
	Result[1][2] = tmp[3] * src[0] + tmp[6] * src[1] + tmp[11] * src[3];
	Result[1][2] -= tmp[2] * src[0] + tmp[7] * src[1] + tmp[10] * src[3];
	Result[1][3] = tmp[4] * src[0] + tmp[9] * src[1] + tmp[10] * src[2];
	Result[1][3] -= tmp[5] * src[0] + tmp[8] * src[1] + tmp[11] * src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0] = src[2] * src[7];
	tmp[1] = src[3] * src[6];
	tmp[2] = src[1] * src[7];
	tmp[3] = src[3] * src[5];
	tmp[4] = src[1] * src[6];
	tmp[5] = src[2] * src[5];

	tmp[6] = src[0] * src[7];
	tmp[7] = src[3] * src[4];
	tmp[8] = src[0] * src[6];
	tmp[9] = src[2] * src[4];
	tmp[10] = src[0] * src[5];
	tmp[11] = src[1] * src[4];
	/* calculate second 8 elements (cofactors) */
	Result[2][0] = tmp[0] * src[13] + tmp[3] * src[14] + tmp[4] * src[15];
	Result[2][0] -= tmp[1] * src[13] + tmp[2] * src[14] + tmp[5] * src[15];
	Result[2][1] = tmp[1] * src[12] + tmp[6] * src[14] + tmp[9] * src[15];
	Result[2][1] -= tmp[0] * src[12] + tmp[7] * src[14] + tmp[8] * src[15];
	Result[2][2] = tmp[2] * src[12] + tmp[7] * src[13] + tmp[10] * src[15];
	Result[2][2] -= tmp[3] * src[12] + tmp[6] * src[13] + tmp[11] * src[15];
	Result[2][3] = tmp[5] * src[12] + tmp[8] * src[13] + tmp[11] * src[14];
	Result[2][3] -= tmp[4] * src[12] + tmp[9] * src[13] + tmp[10] * src[14];
	Result[3][0] = tmp[2] * src[10] + tmp[5] * src[11] + tmp[1] * src[9];
	Result[3][0] -= tmp[4] * src[11] + tmp[0] * src[9] + tmp[3] * src[10];
	Result[3][1] = tmp[8] * src[11] + tmp[0] * src[8] + tmp[7] * src[10];
	Result[3][1] -= tmp[6] * src[10] + tmp[9] * src[11] + tmp[1] * src[8];
	Result[3][2] = tmp[6] * src[9] + tmp[11] * src[11] + tmp[3] * src[8];
	Result[3][2] -= tmp[10] * src[11] + tmp[2] * src[8] + tmp[7] * src[9];
	Result[3][3] = tmp[10] * src[10] + tmp[4] * src[8] + tmp[9] * src[9];
	Result[3][3] -= tmp[8] * src[9] + tmp[11] * src[10] + tmp[5] * src[8];
	/* calculate determinant */
	det = src[0] * Result[0][0] + src[1] * Result[0][1] + src[2] * Result[0][2] + src[3] * Result[0][3];
	/* calculate matrix inverse */
	det = 1.0f / det;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = float(Result[i][j] * det);
		}
	}
	return true;
}

bool CMatrix4::TestHarness()
{
	CMatrix4 MatrixA = CMatrix4();
	CMatrix4 MatrixB = CMatrix4();

	MatrixA.m_fMatrix[0][0] = 8;
	MatrixA.m_fMatrix[1][1] = 7;
	MatrixA.m_fMatrix[2][2] = 6;
	MatrixA.m_fMatrix[3][3] = 5;

	PrintMatrix(MatrixA);
	InitProjMatrix(10);
	Proj(MatrixA, MatrixB);
	PrintMatrix(MatrixA);
	PrintMatrix(MatrixB);
	return false;
}

void CMatrix4::PrintMatrix(CMatrix4& _rMatrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << _rMatrix.m_fMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

CMatrix4& CMatrix4::Rot(const CMatrix4& _rA, CMatrix4& _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				_rResult.m_fMatrix[i][j] += _rA.m_fMatrix[i][k] * m_RMatrix[k][j];
			}
		}
	}
	return _rResult;
}

CMatrix4& CMatrix4::Trans(const CMatrix4& _rA, CMatrix4& _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				_rResult.m_fMatrix[i][j] += _rA.m_fMatrix[i][k] * m_TMatrix[k][j];
			}
		}
	}
	return _rResult;
}

CMatrix4& CMatrix4::Proj(const CMatrix4& _rA, CMatrix4& _rResult)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			_rResult.m_fMatrix[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				_rResult.m_fMatrix[i][j] += m_PMatrix[k][j] * _rA.m_fMatrix[i][k];
			}
		}
	}
	return _rResult;
}

void CMatrix4::SetZero()
{
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			m_fMatrix[y][x] = 0;
		}
	}
	
}

void CMatrix4::InitTMatrix(float _dX, float _dY, float _dZ)
{
	m_TMatrix[0][3] = _dX;
	m_TMatrix[1][3] = _dY;
	m_TMatrix[2][3] = _dZ;
}

void CMatrix4::InitRMatrix(float _dX, float _dY, float _dZ)
{

}

void CMatrix4::InitProjMatrix(float _distance)
{
	m_PMatrix[3][2] = 1 / _distance;
}
