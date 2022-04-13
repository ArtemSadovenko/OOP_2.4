#include "Matrix.h"

int Matrix::count = 0;

void Matrix::create() {
	this->p = new double* [rows];
	for (int i = 0; i < rows; i++) {
		p[i] = new double[cols];
	}

}

void Matrix::full()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] = -9 + rand() % (10 - (-9) + 1);
		}
	}
}





Matrix::Matrix()
{
	rows = 1;
	cols = 1;
	create();
	p[0][0] = 0;
	increase();
}

Matrix::Matrix (int rows, int cols, double** a)
{
	if (rows > max_rows || cols > max_cols) {
		cerr << "Error" << endl;
		exit(1);
	}
	this->rows = rows;
	this->cols = cols;
	create();
	p = a;
	increase();
}

Matrix::Matrix  (int rows, int cols)
{
	if (rows > max_rows || cols > max_cols) {
		cerr << "Error" << endl;
		exit(1);
	}
	this->rows = rows;
	this->cols = cols;
	create();
	full();
	increase();
}

Matrix::Matrix(Matrix& a)
{
	rows = a.rows;
	cols = a.cols;
	create();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] = a.p[i][j];
		}
	}
	increase();
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i) {
		delete[] p[i];
	}
	delete[] p;
}

double& Matrix::operator()(int r, int c)
{
	return p[r][c];
}

Matrix::operator string()
{
	stringstream ss;
	ss << "Matrix:\n\n";
	for (int i = 0; i < rows; i++){
		ss << "|";
		for (int j = 0; j < cols; j++) {
			ss << setw(3) << p[i][j];

		}
		ss << "|\n";
	}
	ss << endl;
	return ss.str();
}

Matrix& Matrix::operator++()
{
	increase();
	rows++;
	return *this;
	// TODO: вставьте здесь оператор return
}

Matrix& Matrix::operator--()
{
	increase();
	rows--;
	return *this;
	// TODO: вставьте здесь оператор return
}

Matrix Matrix::operator++(int)
{
	increase();
	Matrix t(*this);
	cols++;
	return t;
}

Matrix Matrix::operator--(int)
{
	increase();
	Matrix t(*this);
	t = *this;
	cols--;
	return t;
}

Matrix& Matrix::operator=(Matrix& a)
{
	increase();
	rows = a.rows;
	cols = a.cols;
	create();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			p[i][j] = a.p[i][j];
		}
	}
	return *this;
	// TODO: вставьте здесь оператор return
}

double Matrix::norm()
{
	double big = p[0][0];
	double small = p[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (p[i][j] > big) {
				big = p[i][j];
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (p[i][j] < small) {
				small = p[i][j];
			}
		}
	}
	return abs(big - small);
}



ostream& operator<<(ostream& out, const Matrix& b)
{
	out << "Matrix:\n\n";
	for (int i = 0; i < b.rows; i++) {
		out << "|";
		for (int j = 0; j < b.cols; j++) {
			out << setw(3) << b.p[i][j];

		}
		out << "|\n";
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, Matrix& b)
{
	for (int i = 0; i < b.rows; i++) {
		for (int j = 0; j < b.cols; j++) {
			cout << "Enter elemenr: "; in >> b.p[i][j];
			
		}
	}
	return in;
}

Matrix operator-(Matrix& a, Matrix& b)
{
	if (!(a.cols == b.cols && a.rows == b.rows)) {
		cerr << "Error" << endl;
		exit(1);
	}
	Matrix t(a);
	for (int i = 0; i < t.rows; i++) {
		for (int j = 0; j < t.cols; j++) {
			t(i, j) = a(i, j) - b(i, j);
		}
	}
	return t;
}

bool operator>(Matrix a, Matrix b)
{
	if (a.rows * a.cols > b.rows * b.cols) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(Matrix& a, Matrix& b)
{
	return a != b && !(a > b);
}

bool operator==(Matrix& a, Matrix& b)
{
	if (a.rows * a.cols == b.rows * b.cols) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!=(Matrix& a, Matrix& b)
{
	return !(a == b);
}
