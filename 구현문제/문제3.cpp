#include <iostream>

using namespace std;
class Account {
private:
	string Name;
	int Money;
public:
	void insert_money(const int& in_money) {
		try {
			if (in_money < 0)	throw 1;
			Money += in_money;
			cout << "입금 완료 (잔액: " << Money << "원)" << endl;
		}
		catch (int) {
			cout << "입금 오류 : 0보다 큰 금액을 입력하세요." << endl;
		}
	}
	void export_money(const int& out_money) {
		try {
			if (Money < out_money)	throw 1.0f;
			Money -= out_money;
			cout << "출금 완료 (잔액: " << Money << "원)" << endl;
		}
		catch (float) {
			cout << "출금 오류 : 잔액이 부족합니다. (현재 잔액: " << Money << "원)" << endl;
		}
	}
	void review_money() {
		cout << "[잔액 조회] " << Name << "님의 잔액: " << Money << "원" << endl;
	}
	void print_info() {
		cout << "[최종 계좌 정보]" << endl;
		cout << "소유자: " << Name << endl;
		cout << "잔액: " << Money << "원" << endl;
		cout << "프로그램을 종료합니다."<<endl;
	}

	Account(string user_name) : Name(user_name), Money(0) {};
};
int main() {
	string Name;
	string Menu[5] = {
		"===== 계좌 메뉴 =====",
		"1. 입금",
		"2. 출금",
		"3. 잔액 조회",
		"4. 종료"
	};
	bool Is_End = false;
	cout << "계좌 소유자 이름 입력: ";
	cin >> Name;

	Account myAcc(Name);
	while (!Is_End) {
		for (int i = 0; i < 5; i++) {
			cout << Menu[i] << endl;
		}
		int cmd_User, cmd_Money;
		cout << "메뉴 선택: ";
		cin >> cmd_User;	//범위 벗어난 메뉴 등

		switch (cmd_User) {
		case 1:
			cout << "입금 금액: ";
			cin >> cmd_Money;
			myAcc.insert_money(cmd_Money);
			break;
		case 2:
			cout << "출금 금액: ";
			cin >> cmd_Money;
			myAcc.export_money(cmd_Money);
			break;
		case 3:
			myAcc.review_money();
			break;
		case 4:
			myAcc.print_info();
			Is_End = true;
			break;
		}
	}
}