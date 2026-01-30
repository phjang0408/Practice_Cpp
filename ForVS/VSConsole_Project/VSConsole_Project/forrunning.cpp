//생성자와 소멸자 기본

#include <iostream>

using namespace std;

class Base {
public:
	int x;

	// 1) 기본 생성자
	Base() : x(0) {
		cout << "기본 생성자" << endl;
	}

	// 2) 값을 전달받는 생성자
	Base(int value) : x(value) {
		cout << "값을 받는 생성자, 값 : " << value << endl;
	}

	// 3) 생성자에서 다른 생성자 호출
	Base(int a, int b) : x(0) {
		cout << a << b <<"로 나옴" << endl;
	}
	Base(double value) : Base(10, 10) {
		// 여기서 Base(10, 10)을 하면, 변수 저장이 안 됨
		cout << "생성자에서 생성자 직접 호출하기";
	}

	//소멸자
	~Base() {
		cout << "Base 소멸자\n";
	}
};

int main() {
	Base a;
	Base b(1);
	Base c(1, 3);
}