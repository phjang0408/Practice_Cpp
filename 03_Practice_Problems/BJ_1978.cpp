#include <iostream>
using namespace std;
// 버전 1. 하나씩 확인하기 -> O(n)
bool Is_Prime1(const int &number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; i <= number; i += 2)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
// 버전 2. 절반까지 확인하기 - O(n)
bool Is_Prime2(const int &number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; i <= (number / 2); i += 2) // 절반 확인
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
// 버전 3. 제곱근까지 확인하기 -> O(sqrt(n))
bool Is_Prime3(const int &number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; i * i <= number; i += 2) // 제곱근만 확인
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, count = 0, target;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> target;
        if (Is_Prime3(target))
        {
            count++;
        }
    }
    cout << count;
}