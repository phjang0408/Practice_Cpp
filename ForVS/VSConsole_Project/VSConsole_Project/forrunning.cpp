#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    bool found = false;

    for (int i = 1; i < N; i++) {
        int temp = i;
        int num = i;

        while (temp > 0) {
            num += temp % 10;
            temp /= 10;
        }

        if (num == N) {
            cout << i;
            found = true;
            break;
        }
    }

    if (!found)
        cout << 0;
}