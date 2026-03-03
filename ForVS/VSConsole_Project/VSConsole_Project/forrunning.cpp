#include <iostream>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	bool check[42] = {0,};
	int num, result = 0;
	for (int i = 0; i < 10; i++) {
		cin >> num;
		check[num % 42] = true;
	}
	for (bool b : check) {
		if (b)	result++;
	}
	cout << result;
}