#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num_count[10] = {}, a, b, c;
    cin >> a >> b >> c;
    int result = a * b * c;
    while (result > 0)
    {
        num_count[result % 10]++;
        result /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << num_count[i] << '\n';
    }
}