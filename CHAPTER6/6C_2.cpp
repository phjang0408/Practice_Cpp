// 1) 캡슐화 - 세 가지 접근 제어자
#include <iostream>
#include <string>

class Parent {
public:
	std::string publicVar = "누구든 접근 가능한 Public";

protected:
	std::string protectedVar = "자식만 접근 가능 Protected";

private:
	std::string privateVar = "해당 클래스만 접근 가능 Private";
};

//자식 클래스 (public 상속)
class Child : public Parent {
public:
	void accessCheck() {
		std::cout << publicVar << std::endl;		// 가능
		std::cout << protectedVar << std::endl;		// 상속되었으니 가능
		// std::cout << privateVar << std::endl;	// 불가능!
	}
};

int main() {
	Parent p;
	Child c;

	// 1. Public 접근
	std::cout << p.publicVar << std::endl;			// 외부 호출 가능!

	// 2. Protected 접근
	//std::cout << p.protectedVar << std::endl;		// 외부 호출 불가능!
	c.accessCheck();

	// 3. Private 접근
	//std::cout << p.privateVar << std::endl;		// 외부 호출 불가능!

	return 0;
}