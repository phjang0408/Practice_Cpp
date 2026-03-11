#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, r;
    cin >> t;
    string s;
    for (int i = 0; i < t; i++)
    {
        cin >> r >> s;
        for (int k = 0; k < s.size(); k++)
        {
            for (int j = 0; j < r; j++)
            {
                cout << s[k];
            }
        }
        cout << '\n';
    }
}