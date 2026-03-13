#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    array<int, 3> myar;
    while (true)
    {
        cin >> myar[0] >> myar[1] >> myar[2];
        if (myar[0] == 0 && myar[1] == 0 && myar[2] == 0)
        {
            break;
        }
        sort(myar.begin(), myar.end());
        if (myar[0] * myar[0] + myar[1] * myar[1] == myar[2] * myar[2])
            cout << "right\n";
        else
        {
            cout << "wrong\n";
        }
    }
}