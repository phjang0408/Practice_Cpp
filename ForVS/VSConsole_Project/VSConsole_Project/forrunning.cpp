// qo
#include <iostream>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, max_num = -1000000, min_num = 1000000, input;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input > max_num)	max_num = input;
		if (input < min_num)	min_num = input;
	}
	cout << min_num << " " << max_num;
}