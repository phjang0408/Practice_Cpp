// 31403번
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b - c << '\n';

	int to_string = 10, temp_b = b;
	while (temp_b >= 10) {
		temp_b /= 10;
		to_string *= 10;
	}
	cout << a * to_string + b - c << '\n';

	return 0;
}