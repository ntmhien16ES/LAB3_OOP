#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
class matrix
{
private:
	int row;
	int col;
	float** data;
public:
	int getRow(void)
	{
		return this->row;
	}
	int getCol(void)
	{
		return this->col;
	}
	matrix();
	matrix(int, int);
	matrix(float*a[], int ,int);
	bool isSameSize(const matrix&);
	matrix(const matrix&);
	void operator=(const matrix&);
	matrix operator+(const matrix&);
	matrix operator-(const matrix&);
	bool operator==(const matrix&);
	matrix operator*(const matrix&);
	void display();
	friend ostream& operator<<(ostream&, const matrix&);
};

int main()
{
	srand(time(0));
	float** tmp, **tmp2;
	tmp = new float* [3];
	for (int i = 0; i < 3; i++)
		tmp[i] = new float[2];
	tmp2 = new float* [2];
	for (int i = 0; i < 2; i++)
		tmp2[i] = new float[3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			tmp[i][j] = (rand() % (10 - 1)) + 1;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			tmp2[i][j] = (rand() % (10 - 1)) + 1;
		}
	}
	matrix A(tmp, 3, 2), B(tmp2, 2, 3);
	cout << "2 example matrixes: \n";
	cout << ">matrix A: \n";
	cout << A;
	cout << endl<<">matrix B: \n";
	cout << B;
	cout << ">>Testing the multiply operation: \n";
	cout << "A*B = \n" << A * B;
}

matrix::matrix()
{

}
matrix::matrix(int n, int m)
{
	this->row = n;
	this->col = m;
	this->data = new float* [n];
	for (int i = 0; i < n; i++)
	{
		this->data[i] = new float[m];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = 0;
		}
	}
}
bool matrix::isSameSize(const matrix& that)
{
	return (this->row == that.row) && (this->col == that.col);
}
matrix::matrix(float* a[], int m, int n)
{
	this->row = m;
	this->col = n;
	this->data = new float* [m];
	for (int i = 0; i < m; i++)
	{
		this->data[i] = new float[n];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = a[i][j];
		}
	}
}
void matrix::operator=(const matrix & that)
{
	this->row = that.row;
	this->col = that.col;
	this->data = that.data;

}
matrix::matrix(const matrix & that)
{
	this->row = that.row;
	this->col = that.col;
	this->data = new float* [that.row];
	for (int i = 0; i < this->row; i++)
	{
		this->data[i] = new float[this->col];
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->data[i][j] = that.data[i][j];
		}
	}
}
matrix matrix::operator+(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		cout << "Two matrix must have same size!";
		return *this;
	}
	matrix tmpMat(this->row, this->col);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; this->col; j++)
		{
			tmpMat.data[i][j] = this->data[i][j] + that.data[i][j];
		}
	}
	return tmpMat;
}


matrix matrix:: operator-(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		cout << "Two matrix must have same size!\n";
		return *this;
	}
	matrix tmpMat(this->row, this->col);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j <this->col; j++)
		{

			tmpMat.data[i][j] = this->data[i][j] - that.data[i][j];
		}
	}
	return tmpMat;
}
bool matrix::operator==(const matrix & that)
{
	if (!this->isSameSize(that))
	{
		return false;
	}
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j <this->col; j++)
		{
			if (this->data[i][j] != that.data[i][j]) return false;
		}
	}
	return true;
}
matrix matrix::operator*(const matrix & that)
{
	if (this->col != that.row)
	{
		cout << "Error operation!\n";
		return *this;
	}
	matrix tmpMat(this->row, that.col);
	for (int i = 0; i < tmpMat.row; i++)
	{
		for (int j = 0; j < tmpMat.col; j++)
		{
			for (int k = 0; k < this->col; k++)
			{
				tmpMat.data[i][j] += (this->data[i][k]) * (that.data[k][j]);
			}
		}
	}
	return tmpMat;
}
void matrix::display()
{
	for (int i = 0; i < this->row; i++)
	{
		cout << "[";
		for (int j = 0; j < this->col; j++)
		{
			cout << this->data[i][j]<<",";
		}
		cout << "]" << endl;
	}
}
ostream& operator<<(ostream&out, const matrix&that)
{
	for (int i = 0; i < that.row; i++)
	{
		out << "[";
		for (int j = 0; j < that.col; j++)
		{
			out << that.data[i][j]<<",";
		}
		out << "]" << endl;
	}
	return out;
}
