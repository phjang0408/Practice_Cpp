// 2. 부분 정렬
// 지정한 원소까지만 정렬하고, 뒤 쪽은 정렬하지 않는다.
// 부분만 정렬하므로, sort보다 빠르다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> numbers = { 7,2,5,1,8,9,3,6,4 };

	// 가장 작은 원소 [3개]만 정렬
	partial_sort(numbers.begin(), numbers.begin() + 3, numbers.end());

	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << " ";
	}

	return 0;
}