// 컴포지션과 어그레이션
// 다중상속의 대안, 
#include <iostream>
using namespace std;

// 1) 컴포지션 : 강한 소유 관계(Car가 Engine 소유)
class Engine
{
public:
	Engine() {	cout << "Engine created\n";		}
	~Engine() {	cout << "Engine destroyed\n";	}
	void start() {	cout << "Engine Start\n";	}
};

class Car {
private:
	Engine engine;	// 컴포지션(값으로 포함)
public:
	Car() { cout << "Car created\n";	}
	~Car() { cout << "Car destroyed\n"; }
	void drive() {
		engine.start();
		cout << "Car is driving\n";
	}
};

// 2) 어그레이션 : 약한 소유 관계(Person이 Car를 빌려 사용)
class Person {
private:
	Car* car;		// 어그레이션 (포인터로 참조)
public:
	Person(Car* c) : car(c) {}
	void goWork() {
		if (car) {	car->drive();	}
	}
};

int main() {
	Car car;
	car.drive();

	return 0;
}