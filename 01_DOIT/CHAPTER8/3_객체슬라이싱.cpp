// 객체 슬라이싱
#include <iostream>
using namespace std;

class Base {
public:
	int a = 1;
	virtual void print() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
	int b = 2;
	void print() override { cout << "Derived" << endl; }
};

int main() {
	Derived d;
	Base b = d;	// 객체 슬라이싱
	// b가 d의 일부분인 Base 부분만 복사, Derived의 정보는 날아감.

	b.print();

	// 상속 관계에서는, 값으로 받지말고, 참조나 포인터로 받아야 한다.
	return 0;
}