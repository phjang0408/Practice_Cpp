// 함수의 동적바인딩
// 가상함수테이블은 다음 참고
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=dd1587&logNo=221119668089
#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() { cout << "모양 그리기" << endl; }
	virtual void myfun() { cout << endl; }
};

class Circle : public Shape {
public:
	void draw() override { cout << "Circle 그리기" << endl; }
};

int main() {
	Circle circle;			// circle은 정적 타입 'Circle'로 정해짐
	circle.draw();			// 객체로 직접 호출 -> 정적 바인딩

	Shape* shape = &circle;	// 컴파일 할 때는 'Shape' 타입, 그러나 런 타임에 실제 객체는 'Circle'
	shape->draw();			// 부모 타입 포인터로 호출 -> 동적 바인딩

	return 0;
}
/* [용어 정리]
- 정적 바인딩 : 컴파일 시에 할당
- 동적 바인딩 : 프로그램 실행 중에 할당
- vfptr : 가상함수테이블을 가르키는 '함수 포인터 변수', 가상함수가 하나라도 있으면 컴파일러가 생성
- 가상함수테이블 : 가상함수들의 주소 목록

정적 바인딩
	1. 가상함수 X => 메모리에 할당
	2. 가상함수 O => 건드리지 않음

동적 바인딩
	1. 가상함수 X => 이미 할당된 함수 불러옴
	2. 가상함수 O => 재정의된 함수 없으면 가상함수, 있으면 재정의된 함수
*/