// 포인터 동적 메모리 할당
#include <iostream>
#include <string>

using namespace std;

int main() {
	int* pt_int_value = new int;			// 동적 메모리 할당

	*pt_int_value = 100;
	cout << "pointer_int_value = " << *pt_int_value << endl;

	delete pt_int_value;					// 동적 메모리 해제


	int* pt_int_array_value = new int[5];	// 배열 동적 메모리 할당

	for (int i = 0; i < 5; i++) {
		pt_int_array_value[i] = i;
	}

	for (int i = 0; i < 5; i++) {
		cout << "pointer_int_value " << i << "번쨰 값 : " << pt_int_array_value[i] << endl;
	}

	delete[] pt_int_array_value;			// 배열 동적 메모리 해제

	// 예제 [빵 만들기]
	int customer_num = 0;

	cout << "금일 방문객 수 : ";
	cin >> customer_num;

	string* bread = new string[customer_num]; // 손님 수 만큼, 배열 동적 할당

	for (int i = 0; i < customer_num; i++) {
		bread[i] = "빵_" + to_string(i);		// int->string 변환 함수
	}

	cout << endl << "--생산된 빵--" << endl;
	for (int i = 0; i < customer_num; i++) {
		cout << *(bread + i) << endl;
	}

	delete[] bread;

	return 0;
}