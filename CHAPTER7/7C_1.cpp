// 생성자와 소멸자
#include <iostream>

class Player {
public:
	//멤버 변수
	std::string name;
	int age;
	int* hp;	// *동적 할당 멤버* => 깊은 복사에 사용

	// [생성자]
	// 1. 디폴트 생성자
		Player() :									// A. 선언부 : 클래스와 같은 이름, 괄호는 매개변수
		name("unknown"), age(1), hp(new int(100))	// B. 초기화 리스트 : 초기화 할 값들을 지정
	{												// C. 생성자 바디 : 추가적 로직, 계산 등 수행
		std::cout << "디폴트 생성자 호출" << std::endl;
	}

	// 2. 매개변수 생성자
	Player(std::string n, int l) : name(n), age(l), hp(new int(100)) {
		std::cout << "매개변수 생성자 호출, 이름 : " << n << " 레벨 : " << l << " HP : " << *hp <<std::endl;
	}

	// 3. 복사 생성자 (const를 붙여서 원본 값을 보장!)
	Player(const Player& other) : name(other.name), age(other.age),
	hp(new int(*other.hp))		// *복사 생성자*의 사용 이유, 동적메모리를 위해
	{
		std::cout << "복사 생성자 호출" << std::endl;
	}
	/* 왜 깊은 복사를 해야 하나
	* 얕은 복사를 사용하면, 동적 메모리를 두 객체가 같이 가리킴
	* 그래서 소멸자에서 delete 할 때, 같은 곳을 가르키기에, 두 번 delete됨
	* 그래서 복사 생성자를 통해, 새 메모리 할당 + 값 복사가 필수적이다.
	*/

	// [소멸자]
	// 객체가 사라질 때 자동으로 호출
	~Player() {
		// 동적할당변수(new로 생성한 포인터, 배열 등)는 여기서 delete 해야 함.
		delete hp;

		std::cout << name << ": 소멸자 호출(메모리 해제)" << std::endl;
	} 
};

int main() {
	Player p1;				// 디폴트 생성자
	Player p2("JIUK", 27);	// 매개변수 생성자
	Player p3 = p2;			// 복사 생성자(깊은 복사) -> 메모리상의 별도 공간 차지, '복사본' 만들기임

	return 0;
}