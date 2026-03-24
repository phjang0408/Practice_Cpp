#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> sumar;
    int n, call_num, total_sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> call_num;
        call_num == 0 ? sumar.pop() : sumar.push(call_num);
    }
    size_t stack_size = sumar.size();
    for (auto x = 0; x < stack_size; x++)
    {
        total_sum += sumar.top();
        sumar.pop();
    }
    cout << total_sum;
}