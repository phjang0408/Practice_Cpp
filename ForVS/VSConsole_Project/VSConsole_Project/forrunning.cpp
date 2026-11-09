#include <iostream>
#include <string>
#include <vector>

using namespace std;

inline int I_MUL(int x, int y) {
	return x * y;
}

#define M_MUL(x,y) ((x) * (y))

int main(void) {
	cout << I_MUL(1, 2) << endl;
	cout << M_MUL(1, 2) << endl;
	return 0;
}