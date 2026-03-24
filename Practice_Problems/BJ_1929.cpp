#include <iostream>
using namespace std;
bool IsNum(const int& x) {
	if (x == 1)	return false;
	if (x == 2)	return true;
	if (x % 2 == 0)	return false;

	for (int i = 2; i * i <= x; i+=2) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (IsNum(i)) {
			cout << i << '\n';
		}
	}
}