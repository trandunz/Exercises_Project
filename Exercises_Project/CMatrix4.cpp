#include "CMatrix4.h"

CMatrix4::CMatrix4()
{
	SetZero();
}

void CMatrix4::SetElement(int _iX, int _iY, float _fValue)
{
	m_fMatrix[_iY-1][_iX-1] = _fValue;
}

float CMatrix4::GetElement(int _iX, int _iY) const
{
	return m_fMatrix[_iY][_iX];
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

CMatrix4& CMatrix4::CoFactor(const CMatrix4& _rA, CMatrix4& _rResult)
{
	// TODO: insert return statement here
	CMatrix4* TempMatrix = new CMatrix4();
	float TempMatrix[3][3] = { _rResult.m_fMatrix[1][1], _rResult.m_fMatrix[1][2], _rResult.m_fMatrix[1][3],
								_rResult.m_fMatrix[2][1] ,_rResult.m_fMatrix[2][2] ,_rResult.m_fMatrix[2][3], 
								_rResult.m_fMatrix[3][1] ,_rResult.m_fMatrix[3][2] ,_rResult.m_fMatrix[3][3] };
	/*TempMatrix->m_fMatrix = TempMatrix;
	_rResult.m_fMatrix[0][0] = Determinant(TempMatrix);*/

	delete TempMatrix;
	TempMatrix = nullptr;
	return _rResult;
}

bool CMatrix4::Inverse(const CMatrix4& _rA, CMatrix4& _rResult)
{
	return false;
}

bool CMatrix4::TestHarness()
{
	return false;
}

void CMatrix4::PrintMatrix(CMatrix4& _rMatrix)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << _rMatrix.m_fMatrix[i][j];
		}
		std::cout << std::endl;
	}
	
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
