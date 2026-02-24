// 추상클래스
#include <iostream>
using namespace std;

class Shape {
public:
	// '순수 가상 함수'를 하나라도 가지면 추상클래스, 그냥 가상함수는 인스턴스화가 되기 때문에 X
	virtual void draw() = 0;

	// 일반 멤버 함수도 가질 수 있음. 
	void info() { cout << "도형입니다." << endl; }

	// 가상 소멸자
	virtual ~Shape(){}
};

// 파생 클래스
class Circle : public Shape {
public:
	void draw() override { cout << "원을 그립니다." << endl; }
};

class Rectangle : public Shape {
public:
	void draw() override { cout << "사각형을 그립니다." << endl; }
};

int main() {
	// Shape s;		<- 추상클래스는 인스턴스화 불가
	Shape* shape1 = new Circle();
	Shape* shape2 = new Rectangle();

	shape1->info();
	shape1->draw();	// 동적 바인딩 (부모 타입으로 접근하기 때문이지요)

	shape2->info();
	shape2->draw();	// 동적 바인딩

	delete shape1;
	delete shape2;

	return 0;
}