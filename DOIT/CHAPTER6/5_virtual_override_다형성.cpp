// 2) 다형성
// virtual : 가상으로 선언하면, 상속 클래스들이 '오버라이드' 할 수 있다.
// override : 기본 클래스의 가상 메서드를 '재정의'하는 키워드이다.

#include <iostream>
using namespace std;
class Animal {
public:
	// 상속의 관계에서, 가상 함수가 아니면, 무조건 부모 함수로만 호출
	virtual void speak() {
		std::cout << "동물이 소리를 낸다." << std::endl;
	}
};

class Dog : public Animal {
public:
	// 오버라이딩
	void speak() override {
		std::cout << "강아지는 '멍멍' 소리를 낸다." << std::endl;
	}
};

class Cat : public Animal {
public:
	void speak() override final{	// final은 '더 이상 오버라이드, 상속 금지"
		std::cout << "고양이는 '야옹' 소리를 낸다." << std::endl;
	}
};

class Bird{
	public:
	// 상속 괸계가 아닌, 그저 이름만 같은 함수
	void speak(){
		std::cout << "새는 무슨 소리를 낼까?" << std::endl;
	}
};

// 레퍼런스로 호출하기
void makeItSpeak(Animal& animal) {
	animal.speak();
}

int main() {
	Dog Badook;
	Cat Navi;
	Bird Pigeon;

	//부모 타임의 레퍼런스로 자식 객체 전달
	std::cout << "호출 결과" << std::endl;
	makeItSpeak(Badook);
	makeItSpeak(Navi);

	//

	return 0;
}