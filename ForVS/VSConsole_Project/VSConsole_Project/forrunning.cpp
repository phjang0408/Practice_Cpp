// 레퍼런스 변수
#include <iostream>

using namespace std;

void swap(int &ref_a, int &ref_b)	// 매개변수를 '레퍼런스 변수'로 선언
{
	int temp = ref_a;
	ref_a = ref_b;
	ref_b = temp;
}

int main() {
	int a = 5;
	int b = 10;

	cout << "a : " << a << " b : " << b << endl;

	swap(a, b);
	cout << "a : " << a << " b : " << b << endl;

	return 0;
}