#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "정수 입력: ";
    cin >> n;
    // 양수-음수-0 판별
    if (n > 0)
    {
        cout << "입력한 값은 양수입니다." << endl;
    }
    else if (n < 0)
    {

        cout << "입력한 값은 음수입니다." << endl;
    }
    else
    {

        cout << "입력한 값은 0입니다." << endl;
    }

    // 홀수-짝수 판별
    if (n % 2 == 0)
    {
        cout << "입력한 값은 짝수입니다.";
    }
    else
    {
        cout << "입력한 값은 홀수입니다.";
    }

    return 0;
}