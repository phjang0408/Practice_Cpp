#include <iostream>
#include <string>
using namespace std;

/* [설계] 클래스는 데이터 처리(throw)만 담당하고, 
상호작용(UI)은 main이 담당하도록 역할을 분리했습니다.

예외는 "문제를 발견한 곳(=클래스 내부)"에서 던지고(throw),
"흐름을 제어하는 곳(=main)"에서 잡아(catch) 처리합니다. */

// [요구사항] 부모 클래스 MenuItem (추상 클래스)
class MenuItem {
protected:
	string name;			// 메뉴 이름
	int price;				// 가격

public:
	MenuItem() : name(""), price(0) {}
	MenuItem(string n, int p) : name(n), price(p) {}

	string get_name() const { return name; }
	int get_price() const { return price; }

	// [캡슐화] 유효성 검사를 통해 price 변경 제어
	void set_price(int p) {
		if (p <= 0) throw p;
		price = p;
	}

	// [추상화] 순수 가상 함수 — 자식 클래스에서 반드시 구현
	virtual void display() const = 0;

	virtual ~MenuItem() {}
};

// [요구사항] 자식 클래스 CafeItem (상속: MenuItem → CafeItem)
class CafeItem : public MenuItem {
private:
	string category;		// 카테고리 (커피, 음료, 음식 등)

public:
	CafeItem() : MenuItem(), category("") {}
	CafeItem(string n, int p, string cat)
		: MenuItem(n, p), category(cat) {
	}

	string get_category() const { return category; }

	// [상속 + 다형성] 부모의 순수 가상 함수를 override
	void display() const override {
		cout << "[" << category << "] " << name << " - " << price << "원" << endl;
	}
};

// [요구사항] CafeManager 클래스
class CafeManager {
private:
	static const int MAX_MENU = 6;
	static const int MAX_HISTORY = 100;

	CafeItem menu_list[MAX_MENU];		// 메뉴 목록
	int menu_count;						// 등록된 메뉴 수
	int balance;						// 사용자 잔액
	string order_history[MAX_HISTORY];	// 주문 내역
	int order_count;					// 주문 건수

public:
	CafeManager(int money) : balance(money), menu_count(0), order_count(0) {}

	// 메뉴 등록
	void add_menu(string name, int price, string category) {
		menu_list[menu_count++] = CafeItem(name, price, category);
	}

	// 메뉴 출력
	void print_menu() const {
		cout << "\n===== 메뉴 =====" << endl;
		for (int i = 0; i < menu_count; i++) {
			cout << (i + 1) << ". ";
			menu_list[i].display();
		}
		cout << "0. 종료" << endl;
	}
	// 주문 메서드: 유효성 검사 후 예외 throw만 담당, catch문은 main에서 담당
	void order(int menu_idx, int quantity) {
		// [요구사항] 수량 0 이하 시 int형 예외 throw
		if (quantity <= 0) throw quantity;

		int total_price = menu_list[menu_idx].get_price() * quantity;

		// [요구사항] 잔액 부족 시 float형 예외 throw
		if (balance < total_price) {
			// [요구사항] 명시적 형 변환 (int를 float로)
			float shortage = (float)(total_price - balance);
			throw shortage;
		}
		// 결제 완료
		balance -= total_price;
		
		// 주문 내역에 추가 
		string order_info = menu_list[menu_idx].get_name()
			+ " x " + to_string(quantity) 
			+ " = " + to_string(menu_list[menu_idx].get_price() * quantity) +"원";
		order_history[order_count++] = order_info;	
		cout <<endl<< "주문 완료: " << order_info << " (" << total_price << "원)" << endl;
	}

	// 현재 잔액 조회
	void check_balance() {
		cout << "현재 잔액: " << balance << "원" << endl;
	}

	// 잔액 조회 getter
	int get_balance() const { return balance; }

	// 주문 내역 출력
	void print_order_history() {
		cout << "\n===== 주문 내역 =====" << endl;
		if (order_count == 0) {
			cout << "주문 내역이 없습니다." << endl;
		}
		else {
			for (int i = 0; i < order_count; i++) {
				cout << (i + 1) << ". " << order_history[i] << endl;
			}
		}
	}

	// 메뉴 개수 반환
	int get_menu_size() const { return menu_count; }
};

int main() {
	const int Money = 20000;
	CafeManager cafe(Money);

	// 메뉴 등록
	cafe.add_menu("아메리카노", 2000, "커피");
	cafe.add_menu("콜드브루", 3000, "커피");
	cafe.add_menu("바닐라라떼", 3500, "라떼");
	cafe.add_menu("카페라뗴", 3000, "라뗴");
	cafe.add_menu("쿠키", 2500, "음식");
	cafe.add_menu("샌드위치", 7000, "음식");

	int choice = -1;

	// [요구사항] switch와 while로 메인 루프 구성
	while (true) {
		cout << "\n===== 카페 메뉴 =====" << endl;
		cout << "1. 주문하기" << endl;
		cout << "2. 잔액 조회" << endl;
		cout << "3. 주문 내역 조회" << endl;
		cout << "4. 종료" << endl;
		cout << "선택: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			// 주문 메서드
			cafe.print_menu();
			int menu_choice, quantity;
			cout << "메뉴 선택 (숫자): ";
			cin >> menu_choice;

			// 0 입력 시 주문 취소
			if (menu_choice == 0) {
				cout << "주문을 취소합니다." << endl;
				break;
			}

			// 유효 범위 검사
			if (menu_choice < 1 || menu_choice > cafe.get_menu_size()) {
				cout << "잘못된 메뉴입니다." << endl;
				break;
			}

			cout << "수량: ";
			cin >> quantity;

			// [요구사항] try, catch, throw를 활용한 예외 처리
			try {
				cafe.order(menu_choice - 1, quantity);	// order 내부에서 throw 발생
				cout << "[잔액: " << cafe.get_balance() << "원]" << endl;
			}
			// [요구사항] int형 예외 처리
			catch (int qty) {
				cout << "수량 오류: " << qty << "은(는) 유효하지 않습니다." << endl;
			}
			// [요구사항] float형 예외 처리
			catch (float shortage) {
				cout << "결제 오류: " << (int)shortage << "원이 부족합니다." << endl;
			}
			// [요구사항] 예상치 못한 예외 처리
			catch (...) {
				cout << "알 수 없는 오류가 발생했습니다." << endl;
			}
			break;
		}
		case 2:
			cafe.check_balance();
			break;
		case 3:
			cafe.print_order_history();
			break;
		case 4:
			cout << "카페를 이용해주셔서 감사합니다!" << endl;
			return 0;
		default:
			cout << "잘못된 선택입니다." << endl;
		}
	}

	return 0;
}
