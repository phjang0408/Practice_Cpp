// SOLID-5-DIP
// 상위 수준 모듈은 하위 수줄 모듈에 의존해서는 안 되며,
// 상하위 둘 다 '추상 레이어'(인터페이스)에 의존해야 한다.
#include <iostream>
using namespace std;

// 잘못된 설계, 하위 모듈을 바꾸면, 상위 모듈을 수정해야 한다.
class Keyboard{
public:
	void Input() { 
		cout << "Keyboard Input\n"; 
	}
};
class Computer {
private:
	Keyboard keyboard;	// 상위 모듈(Computer)이 하위 모듈(Keyboard)에 의존

public:
	void Use() {
		keyboard.Input(); 
	}
};

// 올바른 설계
// 1. 추상 레이어(인터페이스) 만들기
class IInputDevice {
public:
	virtual void Input() = 0;
	virtual ~IInputDevice() = default;
};

// 2. 구체 클래스는 추상을 구현
class Advanced_Keyboard : public IInputDevice {
public:
	void Input() override {
		cout << "Keyboard Input\n";
	}
};

class Advanced_Mouse : public IInputDevice {
public:
	void Input() override {
		cout << "Mouse Input\n";
	}
};

//3. 상위 모듈은 추상에 의존
class Advanced_Computer {
private:
	IInputDevice& device;
public:
	Advanced_Computer(IInputDevice& d) : device(d){}	// 생성자
	void Use() {
		device.Input();
	}
};

// 상위 모듈(Computer)은 하위 모듈(Keyboard)를 모른다.
// Keyboard에서 Mouse로 변경해도, Computer는 수정이 없다.
// 확장은 열려있고, 수정은 닫혀있다 -> OCP까지 자연스럽게 따라온다.