// 생성자와 소멸자
#include <iostream>

class Player {
public:
	//멤버 변수
	std::string name;
	int age;

	// [생성자]
	// 1. 디폴트 생성자
	Player() :							// A. 선언부 : 클래스와 같은 이름, 괄호는 매개변수
		name("unknown"), age(1)			// B. 초기화 리스트 : 초기화 할 값들을 지정
	{									// C. 생성자 바디 : 추가적 로직, 계산 등 수행
		std::cout << "디폴트 생성자 호출" << std::endl;
	}

	// 2. 매개변수 생성자
	Player(std::string n, int l) : name(n), age(l) {
		std::cout << "매개변수 생성자 호출, 이름 : " << n << " 레벨 : " << l << std::endl;
	}

	// 3. 복사 생성자 (const를 붙여서 원본 값을 보장!)
	Player(const Player& other) : name(other.name), age(other.age) {
		std::cout << "복사 생성자 호출" << std::endl;
	}

	// [소멸자]
	// 객체가 사라질 때 자동으로 호출
	~Player() {
		// new로 생성한 변수(포인터, 배열 등)은 여기서 delete 해야 함.
		std::cout << name << ": 소멸자 호출(메모리 해제)" << std::endl;
	}
};
int main() {
	Player p1;				// 디폴트 생성자
	Player p2("JIUK", 27);	// 매개변수 생성자
	Player p3 = p2;			// 복사 생성자 -> 메모리상의 별도 공간 차지, '복사본' 만들기임

	return 0;
}