// 배열과 포인터의 차이
#include <iostream>

using namespace std;

int main() {
	int array[5] = { 10,20,30,40,50 };
	int* pointer_array = array;

	cout << "array(배열) : " << array << endl;
	cout << "pointer_array(포인터) : " << pointer_array << endl << endl;

	cout << "sizeof(int배열) : " << sizeof(array) << endl;
	cout << "sizeof(포인터) : " << sizeof(pointer_array) << endl;

	// 배열 원소 접근 방식이 포인터 연산으로도 가능하다.
	// 메모리에 접근하는 방식이기 때문이다.
	// 그러나 배열과 포인터는 엄연히 다른 크기를 가졌다.
}