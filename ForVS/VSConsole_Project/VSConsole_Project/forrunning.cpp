// 1) 캡슐화 - 상속 접근 제어자 비교
#include <iostream>
using namespace std;

class Parent {
public:
	void publicMethod() { cout << "publicMethod" << endl; }
protected:
	void protectedMethod() { cout << "protectedMethod" << endl; }
private:
	void privateMethod() { cout << "privateMethod" << endl; }
};

// 1. Public 상속
class PublicChild : public Parent {
public:
	void test() {
		publicMethod();			// 부모의 public : 자식에서도 public, 내부 호출 가능
		protectedMethod();		// 부모의 protected : 자식도 protected, 가능
		//privateMethod();		// 부모의 private는 상속 X
	}
};

// 2. Protected 상속
class ProtectedChild : protected Parent {
public:
	void test() {
		publicMethod();			// 부모의 public : 자식에서 protected로 바뀜, 내부호출만 가능
		protectedMethod();		// 부모의 protected : 자식도 protected, 내부 호출 가능
		//privateMethod();		// 부모의 private는 마찬가지로 상속 X
	}
};

// 3. Private 상속
class PrivateChild : private Parent { // private 생략해도, 디폴트는 private
public:
	void test() {
		publicMethod();			// 부모의 public이 자식에서 private으로 바뀜, 내부에서만 가능
		protectedMethod();		// 부모의 protected도 private로 바뀜, 내부에서만 가능
		//privateMethod();
	}
};

int main() {
	PublicChild pubc;
	pubc.publicMethod();
	// pubc.protectedMethod();	//외부 호출 불가능

	ProtectedChild proc;
	//proc.publicMethod();

	PrivateChild pric;
	//pric.publicMethod();		//불가능 

	return 0;
}