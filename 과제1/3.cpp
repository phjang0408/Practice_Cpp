#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, e;
    cout << "정수 5개 입력: ";
    cin >> a >> b >> c >> d >> e;
    int sum = a + b + c + d + e;
    cout << "총합: " << sum << endl;
    cout << "평균: "  << float(sum) / 5.0 << endl;
    return 0;
}