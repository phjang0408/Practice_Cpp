// SOLID-2-OCP (Open/Closed Principle)
// 확장에는 열려있고, 수정에는 닫혀있어야 한다.
#include <iostream>
using namespace std;

// 잘못된 설계, type이 추가될 떄마다 수정해야 한다.
class Wrong_DamageCalculator {
	int Calculate(string type) {
		if (type == "Warrior")	return 100;
		else if (type == "Mage")	return 80;
		return 0;
	}
};
// 올바른 설계
class Character {
public:
	virtual int CalculateDamage() const = 0;
	virtual ~Character() = default;
};

// 새로운 직업이 추가될 때, 클래스 추가만 하면 됨
class Warrior : public Character {
public:
	int CalculateDamage() const override {
		return 100;
	}
};

class Mage : public Character {
public:
	int CalculateDamage() const override {
		return 80;
	}
};

void PrintDamage(const Character& character) {
	cout << character.CalculateDamage() << endl;
}