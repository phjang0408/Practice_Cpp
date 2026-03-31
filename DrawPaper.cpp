
#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, cnt = 1;
    cin >> n;
    n -= 1;
    for (int i = 1; n > 0; i++)
    {
        if (n - i * 6 >= 0)
        {
            cnt++;
            n = n - (i * 6);
        }
    }
    cout << cnt;
    return 0;
}