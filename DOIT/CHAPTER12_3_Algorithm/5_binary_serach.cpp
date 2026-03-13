// 4. 이진 탐색
// find 함수는 [선형 검색]을 기반으로 동작 : 처음부터 끝까지 탐색 : O(n)
// 이때, [정렬된 범위]에서 특정 값을 찾는 '이진 탐색'을 사용 : O(log n)
// [정렬] 되어 있어야 함!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	vector<int> numbers = { 8,3,1,7,4,5,9,2,6 };
	
	// 1. 정렬 수행
	sort(numbers.begin(), numbers.end());

	int target = 4;	// '4' 찾기

	// 2. 이진 탐색 -> [BOOl] 변수를 반환함!
	bool found = binary_search(numbers.begin(), numbers.end(), target);
	
	found ? cout << "Found!" : cout << "Not Found!";

	return 0;
}