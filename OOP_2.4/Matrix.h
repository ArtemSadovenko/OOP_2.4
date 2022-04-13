#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Matrix
{
    
private:
    const int max_rows = 7;
    const int max_cols = 7;
    int rows, cols;
    double** p;
    static int count;
public:
   
    void create();
    void full();
    int size_r() const { return max_rows; }
    int size_c() const { return max_cols; }
    static void increase() { count++; }
    static int get_count() { return count; }
    
    Matrix();
    Matrix(int rows, int cols, double** a);
    Matrix(int rows, int cols) ;
    Matrix(Matrix& a);
    ~Matrix();

    double& operator () (int r, int c);
    operator string();

    Matrix& operator ++();
    Matrix& operator --();
    Matrix operator ++(int);
    Matrix operator --(int);


    friend ostream& operator <<(ostream& out, const Matrix& b);
    friend istream& operator >>(istream& in, Matrix& b);
    Matrix& operator =(Matrix& a);

    friend Matrix operator - (Matrix& a, Matrix& b);
    friend bool operator > (Matrix a, Matrix b);
    friend bool operator < (Matrix& a, Matrix& b);
    friend bool operator == (Matrix& a, Matrix& b);
    friend bool operator != (Matrix& a, Matrix& b);

    double norm();
};