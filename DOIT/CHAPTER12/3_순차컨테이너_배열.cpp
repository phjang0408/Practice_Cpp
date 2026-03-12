// 순차 컨테이너 - 1. 배열
// 안전함, 정적
#include <iostream>
#include <array>

using namespace std;

int main() {
	array<int, 5> myArray;	// 크기가 5인 int형 배열

	myArray = { 1,2,3,4,5 };
	cout << "배열 출력" << endl;
	for (const int& element : myArray) {
		cout << element << " ";
	}
	cout << endl;

	// 배열 크기 출력
	cout << size(myArray) << endl;		// size = index 개수
	cout << sizeof(myArray) << endl;	// sizeof = index * 자료형 크기

	// 접근, 변경
	myArray[0] = 10;
	cout << "첫 번째 원소 : " << myArray[0] << endl;

	return 0;
}