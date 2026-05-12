//생성자와 소멸자 기본

#include <iostream>

using namespace std;

class Example {
public:
	// 정적 변수, 클래스 당 1개
	static int staticValue;

	// 멤버 변수들
	int a;			// 1) 직접 초기화
	int b;			// 2) 유니폼 초기화
	const int c;	// 3) 상수 변수
	int& ref;		// 4) 레퍼런스
	int d;			// 5) 복사 초기화
	int* ptr;		// 6) 동적 메모리

	// 생성자
	Example(int x)
		: a(x)
		, b{ 10 }
		, c(100)
		, ref(a)
		, d(a)
		, ptr(new int(50))
	{
		cout << "생성자" << endl;
	}

	~Example() {
		delete ptr;
		cout << "소멸자" << endl;
	}
};

int Example::staticValue = 1004;

int main() {
	Example e(5);

	cout << e.a << endl;
	cout << e.b << endl;
	cout << e.c << endl;
	cout << e.ref << endl;
	cout << e.d << endl;
	cout << *e.ptr << endl;
	cout << Example::staticValue << endl;
}