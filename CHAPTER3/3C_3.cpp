// 함수 매개변수 전달 방식
#include <iostream>
using namespace std;

void modifyValue(int n) {
	n + 10;
}

void modifyPointer(int* p) {
	*p + 10;
}

void modifyArray(int array[], int size) {
	/* 관례적으로 배열의 크기도 함께 전달
	배열 매개변수는 포인터이므로, sizeof를 쓰면
	배열 전체 크기가 아닌, 포인터 변수의 크기만 나오기에
	함수 내부에서 sizeof를 통해 배열의 크기를 알 수 없다.*/ 
	for (int i = 0; i < size; i++) {
		array[i] += 10;
	}
}

int main() {
	int num = 5;
	int scores[3] = { 10, 20, 30 };

	modifyValue(num);
	cout << "Value 호출 : " << num << endl;

	modifyPointer(&num);
	cout << "Pointer 호출 : " << num << endl;

	modifyArray(scores, 3);
	for (int i = 0; i < 3; i++) {
		cout << "Array[" << i << "] : " << scores[i] << endl;
	}
	return 0;
}