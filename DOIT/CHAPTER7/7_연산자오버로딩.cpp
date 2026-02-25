// 연산자 오버로딩 - 내가 만드는 특수함수
// 객체끼리의 연산자를 지정, 복사 연산자와 비슷하게, 미리 형식을 만들어야함
// [연산자 오버로딩] : 반환_형식 + operator연산자_기호 + (매개변수) + {...}
// 연산자 기호는
#include <iostream>
using namespace std;

class Player
{
public:
	int hp;

	Player(int h = 0) : hp(h) {}

	// 연산자 오버로딩
	// 연산자 기호, 비교, 증감 기호, (), <<(출력 연산자) 등등
	// .(멤버 접근), ::(범위 지정), sizeof 등, 모든 연산자가 가능하지는 않음
	Player operator+(const Player &other) const
	{
		return Player(hp + other.hp);
	}

	// +=는 자기 자신에게 합치므로, const 불필요
	Player &operator+=(const Player &other)
	{
		hp += other.hp;
		return *this;
	}

	// () operator
	void operator()()
	{
		cout << "현재 플레이어의 HP : " << hp << endl;
	}

	// == operator
	bool operator==(const Player &other) const
	{
		return hp == other.hp;
	}
};

int main()
{
	Player a(50);
	Player b(30);

	Player c;
	c = a + b;			  	// [연산자 '+']
	cout << c.hp << endl; 	// 50 + 30이 나옴

	Player d;
	d += a;				  	// [연산자 '+=']
	cout << d.hp << endl; 	// 0 + 50이 나옴

	d(); 					// [연산자 ()]

	if(d == a){
		cout << "HP가 같습니다." << endl;
	}
	return 0;
}