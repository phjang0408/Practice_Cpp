// 종합 설계 - 
#include <iostream>
using namespace std;

class character {
protected:
	int hp;
	int power;
	void reduce_data(int& attribute, int _damage) {
		if (attribute == 0)	return;
		attribute -= _damage;
		attribute = attribute < 0 ? 0 : attribute;	// 0보다 작으면 0으로 설정
	}

public:
	character() : hp(100), power(100) {};

	int get_hp() { return hp; }
	int get_power() { return power; }
	void set_hp(int _hp) { hp = _hp; }
	void set_power(int _power) { power = _power; }

	virtual void get_damage(int _damage) {	//override할 함수
		reduce_data(hp, _damage);
	}
	void lose_power(int _lose) {
		reduce_data(power, _lose);
	}

	virtual ~character() = default;
};

class player : public character {
public:
	player() {};
	void attack(character& enemy) {
		enemy.get_damage(5);
	}
};

class monster_c : public character {
private:
	int clock;	// 몬스터만 가지는 시간
public:
	monster_c() : clock(60) {
		set_hp(1000);
	}
	//체이닝을 위한 함수
	monster_c& attack(player& target_player);
	monster_c& reduce_power(player& target_player);

	//override를 위한 함수
	virtual void get_damage(int _damage) override;

	// monster만의 함수
	void ticktok();
};

void monster_c::get_damage(int _damage) {
	if (clock < 3)	return;	//override로 추가된 내용. 처음 2초는 공격받지 않음
	reduce_data(hp, _damage);
}
void monster_c::ticktok() {
	clock++;
	clock %= 60;
}

monster_c& monster_c::attack(player& target_player) {
	target_player.get_damage(1);
	return *this;	// 체이닝을 위한 자기 반환
}

monster_c& monster_c::reduce_power(player& target_player) {
	target_player.lose_power(1);
	return *this;	// 체이닝을 위한 자기 반환
}

//전역 함수
void print_out(string title, monster_c mon, player user) {
	cout << title << endl;
	cout << "Monster C: hp(" << mon.get_hp() << "), power(" << mon.get_power() << ")" << endl;
	cout << "Player: hp(" << user.get_hp() << "), power(" << user.get_power() << ")" << endl;
}

int main() {
	monster_c mon;
	player user;

	print_out("게임 시작 전,", mon, user);

	for (int i = 0; i < 60; ++i) {
		user.attack(mon);
		mon.attack(user).reduce_power(user).ticktok();
	}

	print_out("게임 종료 후", mon, user);

	return 0;
}