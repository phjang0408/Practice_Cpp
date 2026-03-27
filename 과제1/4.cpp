#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int start;
    cout << "시작 값 입력: ";
    cin >> start;

    while (true) {
        int menu, num;
        int tmp;

        cout << "===== 메뉴 =====" << endl;
        cout << "1. 덧셈" << endl;
        cout << "2. 뺄셈" << endl;
        cout << "3. 곱셈" << endl;
        cout << "4. 나눗셈" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴 선택: ";
        cin >> menu;

        switch (menu) {
        case 1:
            cout << "계산할 값 입력: ";
            cin >> num;
            tmp = start + num;
            cout << "결과: " << tmp << endl;
            break;

        case 2:
            cout << "계산할 값 입력: ";
            cin >> num;
            tmp = start - num;
            cout << "결과: " << tmp << endl;
            break;

        case 3:
            cout << "계산할 값 입력: ";
            cin >> num;
            tmp = start * num;
            cout << "결과: " << tmp << endl;
            break;

        case 4:
            try {
                cout << "계산할 값 입력: ";
                cin >> num;

                if (num == 0) {
                    throw runtime_error("0으로 나눌 수 없습니다");
                }

                tmp = start / num;
                cout << "결과: " << tmp << endl;
            }
            catch (const runtime_error& e) {
                cout << "예외 발생: " << e.what() << endl;
            }
            break;

        case 5:
            cout << "프로그램을 종료합니다." << endl;
            return 0;

        default:
            cout << "잘못된 메뉴입니다." << endl;
        }
    }

    return 0;
}