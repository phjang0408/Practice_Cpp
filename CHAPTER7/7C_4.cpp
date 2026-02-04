// 추상의 개념
#include <iostream>

using namespace std;

/* 1. Character
* 공통 인터페이스(행동의 규약)를 제공하는 '부모 클래스'
* Player, Monster와 같은 구체적 클래스가 '구현해야 할 행동을 정의'
*/
class Character {
public:
	virtual void Attack() = 0; // 순수 가상 함수 - 파생클래스에서 재정의되어야 하는 함수

	virtual ~Character() {}
};

class Player : public Character {
public:
	void Attack() override {
		cout << "Player Attack" << endl;
	}
};

class Monster : public Character {
public:
	void Attack() override {
		cout << "Monster Attack";
	}
};

// Player or Monster인지 모름
// 그러나 'Attack'할 수 있는, 'Character'라는 건 암.
// OCP 원칙
void DoAttack(Character* c) {
	c->Attack();
}

int main() {
	Player p;
	Monster m;

	DoAttack(&p);
	DoAttack(&m);

	// DoAttack(new Player());
	// DoAttack(new Monster());
}