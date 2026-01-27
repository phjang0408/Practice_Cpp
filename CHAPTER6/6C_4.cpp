// 2) 다형성
#include <iostream>
using namespace std;
class Animal {
public:
	// 가상 함수 선언
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
	void speak() override {
		std::cout << "고양이는 '야옹' 소리를 낸다." << std::endl;
	}
};

// 레퍼런스로 호출하기
void makeItSpeak(Animal& animal) {
	animal.speak();
}

int main() {
	Dog Badook;
	Cat Navi;

	//부모 타임의 레퍼런스로 자식 객체 전달
	std::cout << "호출 결과" << std::endl;
	makeItSpeak(Badook);
	makeItSpeak(Navi);

	return 0;
}