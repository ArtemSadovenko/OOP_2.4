#include "Matrix.h"

int main() {
	Matrix a(4, 4);
	Matrix b(a);
	b(0, 0) += 1;
	cout << a;
	cout << b;
	cin >> b;
	cout << b;
	cout << a - b;

	cout << "a > b " << (a > b) << endl;
	cout << "a < b " << (a < b) << endl;
	cout << "a = b " << (a == b) << endl;
	cout << "a != b " << (a != b) << endl << endl;

	cout << "a norm = " << a.norm() << endl;
	a--;
	--a;
	cout << a;
	cout << a.get_count();
}