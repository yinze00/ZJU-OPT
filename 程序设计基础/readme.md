```C++
#include"pch.h"
#include<iostream>
#include<iomanip>
using namespace std;

class CMatrix {
private:
	int m, n;
	int** matrix;
public:
	CMatrix() :m(0), n(0) {};
	CMatrix(int mm, int nn) :m(mm), n(nn) {
		matrix = new int*[m];
		for (int i = 0;i < m;i++) {
			matrix[i] = new int[n];
			for (int j = 0; j < n; j++)
			{
				matrix[i][j] = 2;
			}	
		}
	};
	//CMatrix_obj<<1<<2<<3<<4<<5<<6;	//矩阵相加 obj1+obj2	//输出矩阵cout<<obj;	
	//CMatrix_obj_1+CMatrix_obj_2
	CMatrix operator+(const CMatrix& k) {
		if (k.m != this->m || k.n != this->n) {
			cerr << "error" << endl;
			exit(-1);
		}
		else {
			//k和*this的行列数相等
			for (int i = 0; i < this->m; i++)
			{
				for (int j = 0; j < this->n; j++)
				{
					this->matrix[i][j] += k.matrix[i][j];
				}
			}
			return *this;
		}
	}
	void operator=(const CMatrix &D) {
		this->m = D.m;
		this->n = D.n;
		this->matrix = new int*[D.m];
		for (int i = 0; i < D.m; i++)
		{
			this->matrix[i] = new int[D.n];
			for (int j = 0; j < D.n; j++)
			{
				this->matrix[i][j] = D.matrix[i][j];
			}
		}
	}
	CMatrix operator<<(int k) {
		CMatrix ans;
		static int rec = 0;
		//m行，n列。  3，4 rec = 8时，赋值
		this->matrix[rec / n][rec%n] = k;
		rec++;
		return *this;
	}

	//cout<<CMatrix_obj
	friend ostream& operator<<(ostream& os, const CMatrix& m) {
		for (int i = 0;i < m.m;i++) {
			for (int j = 0;j < m.n;j++) {
				os << m.matrix[i][j] << "\t";
			} 
			cout << endl;
		}
		return os;
	}
};


int main() {
	CMatrix a(2, 2), b(2, 2);
	a << 1 << 2 << 3 << 4;
	cout << a << endl;
}
```
