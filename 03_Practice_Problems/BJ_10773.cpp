#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main()
{
    vector<int> sumar = {
        0,
    };
    int n, call_num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> call_num;
        call_num == 0 ? sumar.pop_back() : sumar.push_back(call_num);
    }
    cout << std::accumulate(sumar.begin(), sumar.end(), 0);
}