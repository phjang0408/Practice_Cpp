#include <iostream>
#include <string>
using namespace std;

// [요구사항] Account 클래스 정의 (멤버 변수 private, 멤버 함수 public)

// [설계] 클래스는 데이터 처리(throw)만 담당하고, 상호작용(UI)은 main이 담당하도록, 역할을 분리하였습니다.
// 예외 처리에 대해서는, "문제를 발견한 곳(=클래스 내부)"에서 예외만 던지고(throw), 
// "호출하는 쪽, 문제를 해결하거나 흐름을 제어하는 곳(=main)"에서 잡아(catch) 처리합니다.
class Account {
private:
    string name;        // 계좌 소유자 이름
    int balance;        // 잔액 (0으로 초기화)
public:
    // 입금 메서드: 유효성 검사 후 예외 throw, catch문은 main에서 담당
    void insert_money(const int& amount) {
        // [요구사항] 금액 0 이하 시 int형 예외 throw
        if (amount <= 0) throw amount;
        balance += amount;
    }

    // 출금 메서드: 유효성 검사 후 예외 throw만 담당, catch문은 main에서 담당
    void export_money(const int& amount) {
        // [추가구현] 음수 출금금액은 예상 가능한 오류이므로 int형 예외로 명시적으로 처리
        if (amount < 0) throw amount;
        // [요구사항] 잔액 부족 시 float형 예외 throw
        if (balance < amount) throw (float)amount;
        balance -= amount;
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

	// [추가구현] 예외 처리 메세지에서, 현재 잔액을 출력하기 위해, 잔액을 반환하는 메서드 추가로 구현했습니다.
	int get_balance() const {
        return balance;
    }
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
            try {
                myAcc.insert_money(amount);
                cout << "입금 완료 (잔액: " << myAcc.get_balance() << "원)" << endl;
            }
            // [요구사항] int 예외 처리
            catch (int) {
                cout << "입금 오류: 0보다 큰 금액을 입력하세요." << endl;
            }
            // [요구사항] 예상치 못한 예외 처리
            catch (...) {
                cout << "알 수 없는 오류가 발생했습니다." << endl;
            }
            break;
        case 2:
            cout << "출금 금액: ";
            cin >> amount;
            try {
                myAcc.export_money(amount);
                cout << "출금 완료 (잔액: " << myAcc.get_balance() << "원)" << endl;
            }
            /* [추가구현] 음수 출금금액에 대한 int형 예외 처리
               -> catch문에서는 ...으로, '음수 출금금액'인 예외를 처리할 수 있지만,
               catch(...)이 '예상치 못한 오류'를 처리하는 점에 비해, '음수 출금금액'은 비교적 예상 가능한 오류이며,
               catch(...)을 활용하기 위해, 일부러 int를 던지는 것은, 설계가 역전된 거 같았습니다.
               이에 int형 예외로 따로 처리했습니다. */
            catch (int) {
                cout << "출금 오류: 음수 금액은 입력할 수 없습니다." << endl;
            }
            // [요구사항] float 예외 처리
            catch (float) {
                cout << "출금 오류: 잔액이 부족합니다. (현재 잔액: " << myAcc.get_balance() << "원)" << endl;
            }
            // [요구사항] 예상치 못한 예외 처리
            catch (...) {
                cout << "알 수 없는 오류가 발생했습니다." << endl;
            }
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