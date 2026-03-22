#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore();   // 버퍼에서 1개 무시 == 버퍼에서 \n 지우기

    string input;
    for (int i = 0; i < n; i++)
    {
        getline(cin, input);
        input[0] >= 'a' ? input[0] -= ('a' - 'A') : input[0];
        cout << input << '\n';
    }
}