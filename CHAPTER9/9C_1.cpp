// SOLID-1-SRP (Single Responsibility Principle)
// 클래스는 '한 가지 기능'만을 수행하고, '한 가지 이유'로만 변경해야 한다.
#include <iostream>

using namespace std;

// 잘못된 SRP, 플레이어가 동작, 저장 둘 다 책임진다.
class Player {
public:
	void Move() {
		cout << "Player Move\n";
	}
	void SaveToFile() {
		cout << "Save Data\n";
	}
};

// 올바른 SRP, Player는 Player의 역할만을 담당, 변경 이유는 하나여야 한다.
class AdvancedPlayer {
public:
	void Move() {
		cout << "Player Move\n";
	}
};

class Advanced_PlayerFileSaver {
public:
	void Save(const Player& player) {
		cout << "Save Data\n";
	}
};