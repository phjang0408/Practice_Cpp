#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N, MinNum = -1, Sum = 0;
	cin >> M >> N;
	for (int i = ceil(sqrt(M)); i * i <= N; i++) {
		int sq = i * i;
		Sum += sq;
		if (MinNum == -1)
			MinNum = sq;
	}
	if (Sum == 0)	cout << -1;
	else {
		cout << Sum <<'\n'<<MinNum;
	}

}