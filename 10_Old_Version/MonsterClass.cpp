//오버라이딩 호출, 네임스페이스 활용
// 네임스페이스를 사용하면, 원하는 범위의 함수를 호출할 수 있다.

#include <iostream>
using namespace std;

class character {
public:
	character() : hp(100), power(100) {};

protected:
	int hp;
	int power;
};

//character 클래스를 상속 받은 player 클래스
class player : public character {
public:
	player() {};
};

//기본 Monster 클래스
class monster {
public:
	monster() {};
	void get_damage(int _damage) {};
	void attack(player target_player) {};
	void attack_special(player target_player);
};

void monster::attack_special(player target_player) {
	cout << "기본 공격 : 데미지 - 10 hp" << endl;
}

//몬스터 A는 기본 Monster 클래스로부터 상속
class monster_a : public monster, character {
public:
	//상속받은 함수 오버라이딩 
	void attack_special(player target_player);
};

void monster_a::attack_special(player target_player) {
	cout << "인텡글 공격 : 데미지 - 15 hp" << endl;
}

//몬스터 B는 기본 Monster 클래스로부터 상속
class monster_b : public monster, character {
public:
	//상속받은 함수 오버라이딩
	void attack_special(player target_player);
};

void monster_b::attack_special(player target_player) {
	cout << "가상 공격 : 데미지 - 0 hp" << endl;
}

//몬스터 C는 기본 Monster 클래스로부터 상속
class monster_c : public monster, character {
public:
	//상속받은 함수 오버라이딩
	void attack_special(player target_player);
};

void monster_c::attack_special(player target_player) {
	cout << "강력 뇌전 공격 : 데미지 - 100 hp" << endl;
}

int main() {
	player player_1;

	monster_a forest_monster;
	monster_b tutorial_monster;
	monster_c boss_monster;

	cout << "[오버라이딩]" << endl;
	forest_monster.attack_special(player_1);
	tutorial_monster.attack_special(player_1);
	boss_monster.attack_special(player_1);

	// 1. 네임스페이스 활용
	cout << "[기본 클래스 공격]" << endl;
	tutorial_monster.monster::attack_special(player_1);
	forest_monster.monster::attack_special(player_1);
	boss_monster.monster::attack_special(player_1);


	// 2. 자식 클래스를 부모 클레스의 레퍼런스로 접근하면
	monster& Mother_monster = forest_monster;

	// 부모 클래스에 정의된 함수가 호출됨.
	Mother_monster.attack_special(player_1);

	//이때, 부모를 참조(레퍼런스)해도, 자신의 오버라이딩 함수를 호출하려면, 가상함수(virtual)사용
	return 0;
}