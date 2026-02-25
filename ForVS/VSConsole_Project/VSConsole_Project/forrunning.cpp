// 31403번
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int input, asc = 0, des = 9;
	for (int i = 0; i < 8; i++) {
		cin >> input;
		if (input == asc + 1)	asc++;
		if (input == des - 1) des--;
	}
	if (asc == 8) {
		cout << "ascending";
	}
	else if (des == 1) {
		cout << "descending";
	}
	else {
		cout << "mixed";
	}

	return 0;
}