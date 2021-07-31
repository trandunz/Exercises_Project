#include "CMatrix4.h"
#include <iostream>
#include <stdio.h>

CMatrix4::CMatrix4(int _width, int _height)
{
    m_pMatrix = nullptr;
    m_fIdentityMatrix = nullptr;
    m_fZeroMatrix = nullptr;
    width = _width;
    height = _height;
    
}

CMatrix4::~CMatrix4()
{
    delete m_pMatrix;
    m_pMatrix = nullptr;
    m_fIdentityMatrix = nullptr;
    m_fZeroMatrix = nullptr;
}


void CMatrix4::Start()
{
    float** ZeroMatrix = new float* [height]();
    for (int i = 0; i < height; i++) {
        ZeroMatrix[i] = new float[width];
    }
    SetZero(ZeroMatrix);
    m_fZeroMatrix = ZeroMatrix;
    
    float** IdentityMatrix = new float* [height]();
    for (int i = 0; i < height; i++) {
        IdentityMatrix[i] = new float[width];
    }
    SetZero(IdentityMatrix);
    SetIdentity(ZeroMatrix);
    m_fIdentityMatrix = IdentityMatrix;

    float** Matrix = new float* [height]();
    for (int i = 0; i < height; i++) {
        Matrix[i] = new float[width];
    }
    SetZero(Matrix);
    m_pMatrix = Matrix;

    Matrix = nullptr;
    delete[] Matrix;
    
    ZeroMatrix = nullptr;
    delete[] ZeroMatrix;
    
    IdentityMatrix = nullptr;
    delete[] IdentityMatrix;
    

    
}

void CMatrix4::DisplayMatrix()
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            std::cout << m_pMatrix[y][x] << "";
        }
        std::cout << std::endl;
    }
}

bool CMatrix4::TestHarness()
{
    return false;
}

void CMatrix4::SetElement(int _x, int _y, float _value)
{
    _x--;
    _y--;
    m_pMatrix[_y][_x] = _value;
}

float CMatrix4::GetElement(int _x, int _y) const
{
    return m_pMatrix[_y][_x];
}

float** CMatrix4::GetMatrix()
{
    return m_pMatrix;
}

void CMatrix4::SetWidth(int _size)
{
    width = _size;
}

void CMatrix4::SetHeight(int _size)
{
    height = _size;
}

int CMatrix4::GetWidth(const CMatrix4* _matrix)
{
    return _matrix->width;
}

int CMatrix4::GetWidth(const CMatrix4& _A)
{
    return _A.width;
}

int CMatrix4::GetHeight(const CMatrix4* _matrix)
{
    return _matrix->height;
}

int CMatrix4::GetHeight(const CMatrix4& _A)
{
    return _A.height;
}

void CMatrix4::SetZero(float** _pMatrix)
{
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            _pMatrix[y][x] = 0;
        }
    }
}

void CMatrix4::SetIdentity(float** _pMatrix)
{
    for (int y = 0; y < height; y++)
    {
        _pMatrix[y][y] = 1;
    }
}

CMatrix4* CMatrix4::Identity(CMatrix4* _Result)
{
    float** ResultMatrixP = new float* [GetHeight(_Result)]();
    for (int i = 0; i < GetHeight(_Result); i++) {
        ResultMatrixP[i] = new float[GetWidth(_Result)];
    }

    _Result->SetZero(ResultMatrixP);

    for (int y = 0; y < GetHeight(_Result); y++)
    {
        ResultMatrixP[y][y] = 1;
    }

    _Result->m_pMatrix = ResultMatrixP;
    ResultMatrixP = nullptr;
    delete[] ResultMatrixP;
    return _Result;
}

CMatrix4* CMatrix4::Zero(CMatrix4* _Result)
{
    float** ResultMatrixP = new float* [GetHeight(_Result)]();
    for (int i = 0; i < GetHeight(_Result); i++) {
        ResultMatrixP[i] = new float[GetWidth(_Result)];
    }

    for (int y = 0; y < GetHeight(_Result); y++)
    {
        for (int x = 0; x < GetWidth(_Result); x++)
        {
            ResultMatrixP[y][x] = 0;
        }
    }

    _Result->m_pMatrix = ResultMatrixP;
    ResultMatrixP = nullptr;
    delete[] ResultMatrixP;
    return _Result;
    // TODO: insert return statement here
}

bool CMatrix4::Equals(const CMatrix4* _A, const CMatrix4* _B)
{
    if ((_A->GetWidth(_A) == _B->GetWidth(_B)) && (_A->GetWidth(_A) == _B->GetWidth(_B)))
    {
        for (int y = 0; y < _A->GetHeight(_A); y++)
        {
            for (int x = 0; x < _A->GetWidth(_A); x++)
            {
                if (_A->m_pMatrix[y][x] == _B->m_pMatrix[y][x])
                {
                    continue;
                }
                else
                {
                    std::cout << "Matrix A and B are not equal" << std::endl;
                    return false;
                }
                
            }
        }
        std::cout << "Matrix A and B are  equal" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Matrix A and B are not equal" << std::endl;
        return false;
    }
    
}

float CMatrix4::Det(const CMatrix4* _A)
{
    float d = 0.0f;
    CMatrix4* SubMat = new CMatrix4(4, 4);

    float** Matrix = new float* [GetHeight(_A)]();
    for (int i = 0; i < GetHeight(_A); i++) {
        Matrix[i] = new float[GetWidth(_A)];
    }
    for (int y = 0; y < GetHeight(_A); y++)
    {
        for (int x = 0; x < GetWidth(_A); x++)
        {
            Matrix[y][x] = 0;
        }
    }
    SubMat->m_pMatrix = Matrix;

    Matrix = nullptr;
    delete[] Matrix;

    if (GetWidth(_A) == 2)
    {
        return ((_A->m_pMatrix[0][0] * _A->m_pMatrix[1][1]) - (_A->m_pMatrix[1][0] * _A->m_pMatrix[0][1]));
    }
        
    else
    {
        for (int c = 0; c < GetWidth(_A); c++)
        {
            int subi = 0; //submatrix's i value
            for (int i = 0; i < GetWidth(_A); i++)
            {
                int subj = 0;
                for (int j = 0; j < GetWidth(_A); j++)
                {
                    if (j == c)
                    {
                        continue;
                    }
                    else
                    {
                        SubMat->m_pMatrix[subi][subj] = _A->m_pMatrix[i][j];
                        subj++;
                    }
                        
                    
                }
                subi++;

            }
            d = d + (pow(-1, c) * _A->m_pMatrix[0][c] * Det(SubMat));
        }
    }
    delete SubMat;
    SubMat = nullptr;
    std::cout << "Determinent =" << d << std::endl;
    return d;
}

bool CMatrix4::Inverse(const CMatrix4& _A)
{
    return false;
}

const CMatrix4* CMatrix4::Add(const CMatrix4* _A, const CMatrix4* _B)
{

    if ((_A->GetWidth(_A) == _B->GetWidth(_B)) && (_A->GetWidth(_A) == _B->GetWidth(_B)))
    {
        for (int y = 0; y < _A->GetHeight(_A); y++)
        {
            for (int x = 0; x < _A->GetWidth(_A); x++)
            {
                _A->m_pMatrix[y][x] += _B->m_pMatrix[y][x];
            }
        }

        return _A;
    }
    else
    {
        return nullptr;
    }

    // TODO: insert return statement here
}

const CMatrix4* CMatrix4::Subtract(const CMatrix4* _A, const CMatrix4* _B)
{
    if ((_A->GetWidth(_A) == _B->GetWidth(_B)) && (_A->GetWidth(_A) == _B->GetWidth(_B)))
    {
        for (int y = 0; y < _A->GetHeight(_A); y++)
        {
            for (int x = 0; x < _A->GetWidth(_A); x++)
            {
                _A->m_pMatrix[y][x] -= _B->m_pMatrix[y][x];
            }
        }

        return _A;
    }
    else
    {
        return nullptr;
    }

    // TODO: insert return statement here
}

const CMatrix4* CMatrix4::Multiply(const CMatrix4* _A, float _Scalar)
{
    for (int y = 0; y < _A->GetHeight(_A); y++)
    {
        for (int x = 0; x < _A->GetWidth(_A); x++)
        {
            _A->m_pMatrix[y][x] *= _Scalar;
        }
    }

    return _A;

    // TODO: insert return statement here
}

const CMatrix4* CMatrix4::Multiply(const CMatrix4* _A, const CMatrix4* _B)
{
    if ((_A->GetWidth(_A) == _B->GetHeight(_B)))
    {
        for (int y = 0; y < _A->GetHeight(_A); y++)
        {
            for (int x = 0; x < _A->GetWidth(_A); x++)
            {
                _A->m_pMatrix[y][x] = _A->m_pMatrix[y][x] * _B->m_pMatrix[y][x];
            }
        }

        return _A;
    }
    else
    {
        return nullptr;
    }
    // TODO: insert return statement here
}

const CMatrix4* CMatrix4::Transpose(const CMatrix4* _A)
{
    float** ResultMatrixP = new float* [GetHeight(_A)]();
    for (int i = 0; i < GetHeight(_A); i++) {
        ResultMatrixP[i] = new float[GetWidth(_A)];
    }

    for (int y = 0; y < GetHeight(_A); y++)
    {
        for (int x = 0; x < GetWidth(_A); x++)
        {
            ResultMatrixP[y][x] = _A->m_pMatrix[x][y];
        }
    }

    for (int y = 0; y < GetHeight(_A); y++)
    {
        for (int x = 0; x < GetWidth(_A); x++)
        {
            _A->m_pMatrix[y][x] = ResultMatrixP[y][x];
        }
    }

    ResultMatrixP = nullptr;
    delete[] ResultMatrixP;

    return _A;
    // TODO: insert return statement here
}
