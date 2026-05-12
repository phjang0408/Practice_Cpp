#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 재귀함수 (Recursion)
// 함수가 자기 자신을 호출하는 기법
vector<int> v;
void printV(vector<int>& v) {
    for (auto x : v) { cout << x << " "; }
    cout << '\n';
}

void makePermutation(int n, int r, int depth) {
    cout << "n = " << n << " : " << "r = " << r << " : " << "dep = " << depth << '\n';
    if (r == depth) {
        printV(v);
        return;
    }
    for (int i = depth; i < n; i++) {
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);   // 재귀 (depth+1) : DFS방식
        swap(v[i], v[depth]);
    }
    return;
}

int main() {
    for (int i = 1; i <= 3; i++)v.push_back(i);
    makePermutation(3, 3, 0);
    return 0;
}
