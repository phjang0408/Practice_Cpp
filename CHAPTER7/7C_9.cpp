// friend 키워드
// "다른 클래스/함수에게, 내 private,protected [접근 권한]을 준다.
// friend 함수에는 '전역으로 설정하기'와 '다른 클래스에게 열여주기' 두 가지가 있다.
#include <iostream>
using namespace std;

class Player;	// 전방 선언 - Healer의 heal 매개변수가 Player라서

// Player의 friend 클래스 '힐러'
class Healer {
public:
	void heal(Player& p);	// friend키워드를 Player에게서 얻고 난 후에 정의할거임
};

class Player {
private:
	int hp = 100;
	// friend 키워드 함수 1) : 전역 함수
	// 전역 함수처럼 사용할 수 있게 + Player 클래스의 private멤버 '접근 권한'도 생김
	friend void printHP(const Player& p);

	// friend 키워드 함수 2) : 특정 클래스의 특정 멤버 함수
	// "Player 내부를, Healer의 heal 함수에게만 공개한다!"
	friend void Healer::heal(Player& p);

public:
	Player(int h) : hp(h) {}
};

// 1) 전역 friend 함수 정의 -> 전역함수이므로, class 밖에서 정의
void printHP(const Player& p) {
	cout << "HP : "<< p.hp << endl;
}

// 2) Healer 클래스의 멤버 함수 정의 - 24줄에서 Player에게서 권한을 얻고 난 후, 함수를 정의
void Healer::heal(Player& p) {
	p.hp += 50;
}

//friend는 상속되지 않음!
class C : public Healer {
	// 즉, Friend 클래스를 상속받은, C는 hp에 접근할 수 없다.
	// 부모 친구에게 접근할 수 없다
};

int main() {
	Player p(80);
	printHP(p);		// 1) 전역 friend 함수

	Healer h;
	h.heal(p);		// 2) 클래스 멤버 friend 함수
	printHP(p);
	return 0;
}