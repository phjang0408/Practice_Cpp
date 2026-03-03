// 1. static_cast
// 기본적 형 변한, 일반 변수, 열거형(enum), 클래스 업캐스팅에 활용
// 다운캐스트는 검사하지 않으므로, 위험할 수 있음.
#include <iostream>
#include <cstdio>
using namespace std;

class Machine {
public:
	virtual void TurnOn() {
		cout << "I'm MACHINE!!";
	}
};

class Printer : public Machine {
public:
	void TurnOn() override {
		cout << "I'm Printer! ";
	}
	void Print() {
		cout << "PRINTING!";
	}
};
int main() {
	double d = 13.24;
	int tmp_int;

	tmp_int = static_cast<int>(d);	// 1. 일반 변수 타입 (double -> int)
	cout << "static_cast<int>(double) : " << tmp_int << endl;

	enum E {A = 5, B, C};
	E myEnum = E::A;
	int Enum_To_Int = static_cast<int>(myEnum);	// 2. 열거형 타입
	cout << "static_cast<int>(EnumClass) : " << Enum_To_Int << endl;

	// 3. 클래스 (부모 : Machine, 자식 : Printer)
	Printer* myPrinter = new Printer();

	// 3-1  - 업캐스팅 : 자식 -> 부모로 : 안전!
	Machine* machinePtr = static_cast<Machine*>(myPrinter);
	machinePtr->TurnOn();	// Im Printer!

	// 3-2 - 다운캐스팅 : 부모 => 자식으로 : 불안전!!
	Printer* printerPtr = static_cast<Printer*>(machinePtr);
	printerPtr->Print();

	delete myPrinter;
	return 0;

}