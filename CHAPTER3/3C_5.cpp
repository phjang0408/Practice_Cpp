// const : 상수 변수 선언하기
#include <iostream>
using namespace std;

int main() {
	const int a = 10;		// 선언 할 때, 반드시 초기화
	//a = 20 -> 오류 발생

	//포인터 변수의 상수화

	int b = 0;
	const int* ptr_1 = &b;	// *ptr_1 상수화 => 포인터 변수가 '가리키는 값'을 상수화

	b = 1;
	// *ptr_1 = 2; -> 오류 발생

	int c = 0;
	int d = 1;
	int* const ptr_2 = &c;	// ptr_2 상수화 => '포인터 변수'를 상수화

	c = 1;
	// ptr_2 = &d -> 오류 발생
}

/*
const 오른쪽의 값을 상수화 한다.

const int* p;  -> 값 못 바꿈
int* const p;  -> 주소 못 바꿈
*/