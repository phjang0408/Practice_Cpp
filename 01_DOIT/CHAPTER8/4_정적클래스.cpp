// 정적멤버 'static'의 활용
#include <iostream>
using namespace std;

// 정적 클래스(정적 멤버로만 구성된 클래스, 공식용어 X)
class GameUtil {
public:
	GameUtil() = delete;	// 객체 생성 금지

	static void printLine() { cout << "---------------" << endl; }
};

class Monster {
private:
	int hp;
	Monster(int hp) :hp(hp) {}	// 외부 생성을 못하게 private로
public:
	void info() { cout << "Monster HP : " << hp << endl; }

	// [정적 팩토리 함수]
	static Monster createNormal() {
		return Monster(100);
	}

	static Monster createBoss() {
		return Monster(500);
	}
	// '팩토리 패턴'은 "객체를 어떻게 만들지 숨기고, 무엇을 만들지 드러내는 설계"
	// 공장에 주문 후, 받아오는 패턴. 내부 생산 과정은 몰라도 되는 설계
};

int main() {
	// 1. 정적 클래스 사용 (인스턴스화X)
	GameUtil::printLine();

	// 2. 정적 멤버 함수로 객체 생성
	Monster m1 = Monster::createNormal();
	Monster m2 = Monster::createBoss();

	m1.info();
	m2.info();

	GameUtil::printLine();

	return 0;
}