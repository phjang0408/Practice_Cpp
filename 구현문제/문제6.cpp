#include <iostream>
#include <string>
#include <vector>
using namespace std;

// [요구사항] 부모 클래스 MenuItem
class MenuItem {
protected:
	string name;			// 메뉴 이름
	int price;				// 가격

public:
	MenuItem(string n, int p) : name(n), price(p) {}

	string get_name() const { return name; }
	int get_price() const { return price; }

	virtual ~MenuItem() {}
};

// [요구사항] 자식 클래스 CafeItem (상속: MenuItem → CafeItem)
class CafeItem : public MenuItem {
private:
	string category;		// 카테고리 (커피, 음료, 음식 등)

public:
	CafeItem(string n, int p, string cat)
		: MenuItem(n, p), category(cat) {}

	string get_category() const { return category; }

	void print_info() const {
		cout << "[" << category << "] " << name << " - " << price << "원" << endl;
	}
};

// [요구사항] CafeManager 클래스
class CafeManager {
private:
	vector<CafeItem> menu_list;		// 메뉴 목록
	int balance;					// 사용자 잔액
	vector<string> order_history;	// 주문 내역

public:
	CafeManager() : balance(10000) {}

	// 메뉴 등록
	void add_menu(string name, int price, string category) {
		menu_list.push_back(CafeItem(name, price, category));
	}

	// 메뉴 출력
	void print_menu() const {
		cout << "\n===== 메뉴 =====" << endl;
		for (int i = 0; i < (int)menu_list.size(); i++) {
			cout << (i + 1) << ". ";
			menu_list[i].print_info();
		}
		cout << "0. 종료" << endl;
	}

	// 주문 메서드 (예외 처리)
	void order(int menu_idx, int quantity) {
		try {
			// [요구사항] 수량 0 이하 시 int형 예외 throw
			if (quantity <= 0) throw quantity;

			int total_price = menu_list[menu_idx].get_price() * quantity;

			// [요구사항] 잔액 부족 시 float형 예외 throw
			if (balance < total_price) {
				float shortage = (float)(total_price - balance);
				throw shortage;
			}

			// 결제 완료
			balance -= total_price;
			string order_info = menu_list[menu_idx].get_name()
				+ " x" + to_string(quantity);
			order_history.push_back(order_info);
			cout << "주문 완료: " << order_info << " (" << total_price
				 << "원) [잔액: " << balance << "원]" << endl;

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
	}

	// 현재 잔액 조회
	void check_balance() {
		cout << "현재 잔액: " << balance << "원" << endl;
	}

	// 주문 내역 출력
	void print_order_history() {
		cout << "\n===== 주문 내역 =====" << endl;
		if (order_history.empty()) {
			cout << "주문 내역이 없습니다." << endl;
		} else {
			for (int i = 0; i < (int)order_history.size(); i++) {
				cout << (i + 1) << ". " << order_history[i] << endl;
			}
		}
	}

	// 메뉴 개수 반환
	int get_menu_size() const { return menu_list.size(); }
};

int main() {
	CafeManager cafe;

	// 메뉴 등록
	cafe.add_menu("아메리카노", 3000, "커피");
	cafe.add_menu("카페라떼", 4500, "커피");
	cafe.add_menu("초콜릿", 5000, "음료");
	cafe.add_menu("우유", 2000, "음료");
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

			// [요구사항] 명시적 형 변환 (int를 float로)
			cafe.order(menu_choice - 1, quantity);
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
