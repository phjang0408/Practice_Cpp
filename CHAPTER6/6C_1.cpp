// 클래스
#include <iostream>

using namespace std;
// 1. 기본 구조 : 멤버 변수 + 멤버 함수
class bank {
private:
	int safe;

public:
	bank(); // 2-1. 생성자
	void use_counter(int _in, int _out);

	~bank(){ // 2-2. 소멸자
		cout << "금고 소멸!" << endl;
	}
};
// 2. 생성자
bank::bank() {
	safe = 1000;
	cout << "최초 금고 : " << safe << endl;
	cout << endl;
}

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;

	cout << "입금 : " << _in << endl;
	cout << "출금 : " << _out << endl;
	cout << "금고 : " << safe << endl;
	cout << endl;
}

int main() {
	bank my_bank;					// 3-1 스택에 객체 생성, 이름으로 선언하면 됨
	bank *heap_bank = new bank(); 	// 3-2 힙에 객체 생성, new + delete키워드 사용, 수동으로 관리

	my_bank.use_counter(0,20);		//출금 20
	my_bank.use_counter(20, 0);		// 입금 50
	my_bank.use_counter(100, 50);	// 입금 100, 출금 50

	delete heap_bank;				// 힙 객체는 소멸하지 않으면, 메모리 누수 발생

	return 0;
}