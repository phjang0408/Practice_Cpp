#include <iostream>

// 1934번 최소공배수 구하기
int get_gcd(int a, int b) {
	int gcd;
	for (int i = 1; i <= a || i <= b; i++) {
		if (a % i == 0 && b % i == 0)	gcd = i;
	}
	return gcd;
}

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		int a, b;
		int gcd = 1;
		std::cin >> a >> b;
		gcd = get_gcd(a, b);
		std::cout << gcd * (a/gcd) * (b/gcd) << std::endl;
	}
}