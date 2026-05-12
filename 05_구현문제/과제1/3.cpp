#include <iostream>
#include <iomanip> // 소수점 헤더
using namespace std;
int main()
{
    int n, sum = 0;
    cout << fixed;           // 고정 소수점 방식으로 표시
    cout << setprecision(1); // 소수점 아래 한 자리까지 출력

    cout << "정수 5개 입력: ";
    for (int i = 0; i < n; i++)
    {
        cin >> n;
        sum += n;
    }
    float avg = float(sum) / 5;

    cout << "총합: " << sum << endl;
    cout << "평균: " << avg << endl;

    return 0;
}