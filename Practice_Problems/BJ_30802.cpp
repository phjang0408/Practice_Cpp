#include <iostream>
#include <array>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, t, p;
	int T_Count = 0;
	cin >> n;
	array<int, 6> sizeArray;

	for (int& i : sizeArray) {
		cin >> i;
	}
	cin >> t >> p;
	for (int& i : sizeArray) {
		T_Count += (i + t - 1) / t;		// 올림연산 
	}
	cout << T_Count << '\n' << n / p << " " << n % p;
}