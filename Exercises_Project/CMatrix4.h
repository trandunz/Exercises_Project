#pragma once
class CMatrix4
{
public:
	

	CMatrix4(int _width, int _height);
	~CMatrix4();


	void Start();

	void DisplayMatrix();

	static bool TestHarness();

	void SetElement(int _x, int _y, float _value);
	float GetElement(int _x, int _y) const;

	float** GetMatrix();
	void SetWidth(int _size);
	void SetHeight(int _size);
	static int GetWidth(const CMatrix4* _matrix);
	static int GetWidth(const CMatrix4& _A);
	static int GetHeight(const CMatrix4* _matrix);
	static int GetHeight(const CMatrix4& _A);

	

	static CMatrix4* Identity(CMatrix4* _Result);
	static CMatrix4* Zero(CMatrix4* _Result);

	static bool Equals(const CMatrix4* _A, const CMatrix4* _B);
	static float Det(const CMatrix4* _A);
	static bool Inverse(const CMatrix4& _A);

	static const CMatrix4* Add(const CMatrix4* _A, const CMatrix4* _B);
	static const CMatrix4* Subtract(const CMatrix4* _A, const CMatrix4* _B);
	static const CMatrix4* Multiply(const CMatrix4* _A, float _Scalar);
	static const CMatrix4* Multiply(const CMatrix4* _A, const CMatrix4* _B);
	static const CMatrix4* Transpose(const CMatrix4* _A);

private:
	int width;
	int height;

	float** m_pMatrix;
	float** m_fIdentityMatrix;
	float** m_fZeroMatrix;

	void SetZero(float** _pMatrix);
	void SetIdentity(float** _pMatrix);

	
};

