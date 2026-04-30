#include <iostream>
#include <string>
using namespace std;

// [요구사항] Account 클래스 정의 (멤버 변수 private, 멤버 함수 public)
class Account {
private:
	string name;		// 계좌 소유자 이름
	int balance;		// 잔액 (0으로 초기화)
public:
	// 입금 메서드
	void insert_money(const int& amount) {
		try {
			// [요구사항] 금액 0 이하 시 int형 예외 throw
			if (amount <= 0) throw amount;
			balance += amount;
			cout << "입금 완료 (잔액: " << balance << "원)" << endl;
		}
		// [요구사항] int 예외 처리
		catch (int err) {
			cout << "입금 오류: 0보다 큰 금액을 입력하세요." << endl;
		}
		// [요구사항] 예상치 못한 예외 처리
		catch (...) {
			cout << "알 수 없는 오류가 발생했습니다." << endl;
		}
	}

	// 출금 메서드
	void export_money(const int& amount) {
		try {
			// [요구사항] 금액 0 이하 시 int형 예외 throw
			if (amount <= 0) throw amount;
			// [요구사항] 잔액 부족 시 float형 예외 throw
			if (balance < amount) throw (float)amount;
			balance -= amount;
			cout << "출금 완료 (잔액: " << balance << "원)" << endl;
		}
		// [요구사항] int 예외 처리
		catch (int err) {
			cout << "출금 오류: 0보다 큰 금액을 입력하세요." << endl;
		}
		// [요구사항] float 예외 처리
		catch (float shortage) {
			cout << "출금 오류: 잔액이 부족합니다. (현재 잔액: " << balance << "원)" << endl;
		}
		// [요구사항] 예상치 못한 예외 처리
		catch (...) {
			cout << "알 수 없는 오류가 발생했습니다." << endl;
		}
	}

	// 잔액 조회 메서드
	void review_money() {
		cout << "[잔액 조회] " << name << "님의 잔액: " << balance << "원" << endl;
	}

	// 최종 정보 출력 메서드
	void print_info() {
		cout << "[최종 계좌 정보]" << endl;
		cout << "소유자: " << name << endl;
		cout << "잔액: " << balance << "원" << endl;
		cout << "프로그램을 종료합니다." << endl;
	}

	// 생성자: 이름으로 초기화, 잔액은 0으로
	Account(string user_name) : name(user_name), balance(0) {}
};

int main() {
	string owner_name;
	string menu[5] = {
		"===== 계좌 메뉴 =====",
		"1. 입금",
		"2. 출금",
		"3. 잔액 조회",
		"4. 종료"
	};
	bool is_end = false;
	cout << "계좌 소유자 이름 입력: ";
	cin >> owner_name;

	Account myAcc(owner_name);

	// [요구사항] switch 문으로 메뉴 처리
	while (!is_end) {
		for (int i = 0; i < 5; i++) {
			cout << menu[i] << endl;
		}
		int menu_choice, amount;
		cout << "메뉴 선택: ";
		cin >> menu_choice;

		switch (menu_choice) {
		case 1:
			cout << "입금 금액: ";
			cin >> amount;
			myAcc.insert_money(amount);
			break;
		case 2:
			cout << "출금 금액: ";
			cin >> amount;
			myAcc.export_money(amount);
			break;
		case 3:
			myAcc.review_money();
			break;
		case 4:
			myAcc.print_info();
			is_end = true;
			break;
		default:
			cout << "잘못된 메뉴 선택입니다." << endl;
			break;
		}
	}

	return 0;
}