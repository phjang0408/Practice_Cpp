// 3. reinterpret_cast
// 타입무시, 메모리 비트를 재해석하는 형변환
// 강력하지만, 안정적이지 않고, 컴파일은 가능
#include <iostream>
using namespace std;
int main() {
	int number = 10;

	// 1. 포인터 -> 정수
	int* ptr = &number;
	long Address = reinterpret_cast<long>(ptr);
	cout << "주소값 : " << Address << endl;

	// 2. 정수 -> 포인터
	int* restoredPtr = reinterpret_cast<int*>(Address);
	cout << "복원된 값 : " << *restoredPtr << endl;

	// 3. 관계없는 포인터 타입 변환
	double* wrongPtr = reinterpret_cast<double*>(ptr);	// int* -> double*
	// cout << *wrongPtr // 매우 위험함!
	return 0;
}