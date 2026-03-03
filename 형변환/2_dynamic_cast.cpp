// 2. dynamic_cast
// 상속 - 특히 다운캐스트에서 많이 사용한다.
// 실패 시 nullptr를 반환하고, 런타임에 실제 객체를 확인한다.
#include <iostream>
using namespace std;

class Machine {
public:
	virtual void TurnOn() {		// dynamic_cast는 [반드시 가상함수 필요](RTTI 조건)
		cout << "I'm MACHINE!!\n";
	}
};

class Printer : public Machine {
public:
	void TurnOn() override {
		cout << "I'm Printer!\n";
	}
	void Print() {
		cout << "PRINTING!\n";
	}
};
int main() {
	Machine* machinePtr = new Printer();

	// 1. 업캐스트 : 자식 -> 부모
	Machine* up = dynamic_cast<Machine*>(machinePtr);
	up->TurnOn();

	// 2. 다운캐스트 (런타임에 검사를 수행) : 부모 -> 자식
	Printer* down = dynamic_cast<Printer*>(machinePtr);

	if (down) {		// 캐스팅 실패 시, nullptr를 반환하기에, 이런 처리가 가능하다.
		down->Print();
	}

	// 3. 실패
	Machine baseObj;
	Machine* basePtr = &baseObj;

	Printer* fail = dynamic_cast<Printer*>(basePtr);
	if (fail == nullptr) {
		cout << "다운캐스트 실패 -> nullptr 반환\n";
	}

	delete machinePtr;
	return 0;
}