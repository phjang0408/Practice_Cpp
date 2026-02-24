// 생성자와 소멸자 - 심화
#include <iostream>
#include <string>

class Player {
public:
	//멤버 변수
	std::string* name;

	// [기본] - 매개변수 생성자
	Player(std::string n) {
		name = new std::string(n);
		std::cout << *name << ": 생성자 호출 (메모리 할당)" << std::endl;
	}

	// [심화 1] 복사 대입 연산자
	//p3 = p2 처럼 이미 생성된 객체끼리, 값을 복사할 때 사용
	Player& operator = (const Player& other) {
		if (this == &other) return *this; // 자기자신은 대입 X

		delete name;	//기존 메모리 해제
		name = new std::string(*other.name); // 깊은 복사
		std::cout << *name << ": 대입 연산자 호출" << std::endl;
		return *this;
	}

	// [심화 2] : 이동 생성자
	// 임시 객체의 메모리 주소를 뺏어옴(소유권 이전, 주소만 바꾸는 방식)
	// &&은 자원을 빼앗아도 되는 객체
	// noexcept로, 예외 없음을 보장해야, 이동이 가능
	Player(Player&& other) noexcept : name(other.name) {
		other.name = nullptr;	//원본 포인터 끊기
		std::cout << "이동 생성자 호출" << std::endl;
	}

	// [심화 3] : 가상 소멸자
	// 상속 관계에서, 자식 객체가 안전하게 지워지도록 보장함
	virtual ~Player() {
		if (name != nullptr) {
			std::cout << *name << ": 소멸자 호출(메모리 해제)" << std::endl;
			delete name;
		}
	}
};

// [가상 소멸자]를 위한 자식 클래스 
class Warrior : public Player {
public:
	int* weaponPower;	// 자식 클래스 - 동적할당 멤버

	// 생성자
	Warrior(std::string n, int power) : Player(n), weaponPower(new int(power)) {
		std::cout << "Warrior 생성" << std::endl; 
	}

	//소멸자
	~Warrior() {
		delete weaponPower;		// 동적 할당 해제
		std::cout << "Warrior 소멸" << std::endl;
	}
};
int main() {
	Player p1("JIUK");			// 생성자
	Player p2("Minji");

	p2 = p1;					// 복사 대입 연산자

	Player p3 = std::move(p1);	// 이동 생성자(p1의 자원을 p3로 뺏어옴, p1은 nullptr이 됨)

	// 가상소멸자 - 자식 객체를 [부모 타입의 포인터]로 가리킴
	Player* p = new Warrior("Biking", 100);
	delete p;		// p의 타입이 Player*이지만, 가상 소멸자 덕분에, 실제 객체 Warrior를 찾아감
	// 가상 소멸자가 없으면 -> Player 소멸자만 호출, Warrior 소멸자는 무시
	// 가상 소멸자가 있으면 -> Warrior 소멸자 호출 -> Player 소멸자 호출

	return 0;
}