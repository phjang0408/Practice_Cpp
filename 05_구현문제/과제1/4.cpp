#include <iostream>
using namespace std;

int main()
{
    int input;
    cout << "시작 값 입력: ";
    cin >> input;

    while (true)
    {
        int menu, num;

        cout << "\n===== 메뉴 =====" << endl;
        cout << "1. 덧셈" << endl;
        cout << "2. 뺄셈" << endl;
        cout << "3. 곱셈" << endl;
        cout << "4. 나눗셈" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴 선택: ";
        cin >> menu;

        // 5번 종료와 잘못된 입력(default)을 모두 switch에서 처리
        switch (menu)
        {
        case 1:
            cout << "계산할 값 입력: ";
            cin >> num;
            input = input + num;
            cout << "결과: " << input << endl;
            break;

        case 2:
            cout << "계산할 값 입력: ";
            cin >> num;
            input = input - num;
            cout << "결과: " << input << endl;
            break;

        case 3:
            cout << "계산할 값 입력: ";
            cin >> num;
            input = input * num;
            cout << "결과: " << input << endl;
            break;

        case 4:
            // try문
            try
            {
                cout << "계산할 값 입력: ";
                cin >> num;
                if (num == 0)
                {              // 0으로 나누기면,
                    throw '.'; // 문자로 에러 던지기
                }
                input = (int)((double)input / num); // 소수점은 버리고 다시 저장
                cout << "결과: " << input << endl;
            }
            catch (char e)
            { // 문자 에러 받기
                cout << "예외 발생: 0으로 나눌 수 없습니다" << e << endl;
            }
            break;

        case 5:
            cout << "프로그램을 종료합니다." << endl;
            return 0;

        default:
            cout << "잘못된 메뉴입니다. 다시 선택해주세요." << endl;
            break;
        }
    }

    return 0;
}