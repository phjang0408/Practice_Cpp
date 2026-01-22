// 어센셜을 이용한 예외처리
#include <iostream>
#include <cassert>		//assert 매크로를 포함하는 헤더파일
using namespace std;

void print_num(int* _pt_int) {
	assert(_pt_int != NULL);	// 디버그모드에서 NULL인지 검사, 구문이 false면 프로그램 종료
	cout << *_pt_int << "@@" << endl;
}

int main() {
	int a = 100;
	int* b = NULL;
	int* c = NULL;

	//b는 NULL이 아닌 상태로 전달
	b = &a;
	print_num(b);

	cout << "Is print_num(b) is Runned?" << endl;
	//c는 NULL 상태로 전달
	print_num(c);

	/*
	실행 시, assert(c)*/
	return 0;
}