#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 순열 (Permutation)
// next_permutation을 이용한 구현, 재귀 구현

int main() {
    ios_base::sync_with_stdio(false);

    // 1. vector 버전
    vector<int> a = { 1,2,3 };
    sort(a.begin(), a.end());
    do {
        for (auto x : a) {
            cout << x << " ";
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

    // 2. array 버전
    int b[] = { 1,2,3 };
    sort(&b, &b + 3);
    do {
        for (auto x : b) {
            cout << x << " ";
        }
        cout << '\n';
    } while (next_permutation(&b, &b + 3));

    return 0;
}
