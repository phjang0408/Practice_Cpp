// 멤버 함수 체이닝
#include <iostream>
using namespace std;

class Player {
	int hp = 100;

public:
    // 체이닝 구현 시, 반환 값을 [레퍼런스 형식]나 [포인터]
	Player& damage(int d) {
		hp -= d;
		return *this;	// 반환 값
	}

	Player& heal(int h) {
		hp += h;
		return *this;
	}

	void print() const {
		cout << "HP : " << hp << endl;
	}
};

int main() {
	Player p;
	p.damage(30).heal(10).damage(5);	// [체이닝]
	p.print();

	return 0;
}