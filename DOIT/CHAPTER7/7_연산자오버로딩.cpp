// 연산자 오버로딩
// 객체끼리의 연산자를 지정, 복사 연산자와 비슷하게, 미리 형식을 만들어야함
// [연산자 오버로딩] : "반환_형식 operator연산자_기호(매개변수)"
#include <iostream>
using namespace std;

class Player {
public:
	int hp;

	Player(int h=0) : hp(h){}

	// 연산자 오버로딩 '+'
	// operator와 뒤에 '+','*','-=' 등, 연산자 기호는 전부 가능
	// 뒤에 const는 자기 자신을 보호
	Player operator+(const Player& other) const {
		return Player(hp + other.hp);
	}

	// +=는 자기 자신에게 합치므로, const 불필요
	Player& operator+=(const Player& other) {
		hp += other.hp;
		return *this;
	}
};

int main() {
	Player a(50);
	Player b(30);

	Player c;
	c = a + b;				// [연산자 '+']
	cout << c.hp << endl;	// 50 + 30이 나옴

	Player d;
	d += a;					// [연산자 '+=']
	cout << d.hp << endl;	// 0 + 50이 나옴
	
	return 0;
}