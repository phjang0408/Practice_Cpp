// SOLID-3-LSP (Liskov Substitution Principle)
// 자식은 부모를 완전히 대체할 수 있어야 한다.
#include <iostream>
using namespace std;

// 잘못된 설계, 자식이 부모를 대체할 수 없음
class Bird {
public:
	virtual void Fly() {
		cout << "Flying" << endl;
	}
};
// (펭귄은 날 수 없음, 즉 부모를 대체하지 못함)
class Penguin : public Bird {
	void Fly() override {
		throw runtime_error("Penguins can't fly!");
	}
};

// 올바른 설계, 상속은 is-a 관계가 성립할 때에만, 기능이 다르면 계층을 나눠야 한다.
class Advanced_Bird{
};

class FlyingBird : public Advanced_Bird {
public:
	virtual void Fly() = 0;
};

class Sparrow : public FlyingBird {
public:
	void Fly() override {
		cout << "Flying" << endl;
	}
};

class Advanced_Penguin : public Bird {
};