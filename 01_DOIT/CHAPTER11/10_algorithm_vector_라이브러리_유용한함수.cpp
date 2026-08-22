// algorithm + vector 유용한 함수
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>	// 7. accumulate 

using namespace std;

template <typename T>
void print_Vector(const vector<T>& t) {
	for (const auto& num : t) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	vector<int> myVector = { 3,1,2,4, 4,4 };

	// 1. reverse -> 뒤집기
	std::reverse(myVector.begin(), myVector.end());
	print_Vector(myVector);

	// 2. sort -> 정렬 + stable_sort, nth_element, is_sorted ...
	std::sort(myVector.begin(), myVector.end());
	print_Vector(myVector);

	// 3. find -> 요소를 찾아, 해당 위치 반환 + find_if
	auto it = std::find(myVector.begin(), myVector.end(), 3);
	cout << "3 is founded here : " << std::distance(myVector.begin(), it) << endl;

	// 4. max, min -> 최대, 최소
	cout << "Max : " << std::max(1, 10) << " Min : " << std::min(1, 10) << endl;

	// 5. count -> 개수 확인 + count_if
	cout << "Numbers of 4 : " << count(myVector.begin(), myVector.end(), 4) << endl;
	cout << "(count_if)Numbers of > 3 : " << 
	count_if(myVector.begin(), myVector.end(), [](int n){return n > 3;}) << endl;
	
	// 6. for_each -> 범위 요소들에, 특정동작 수행
	std::for_each(myVector.begin(), myVector.end(), [](int& x) {x *= 2; });
	print_Vector(myVector);

	// 7. ammulate -> 범위 값을 합
	int sum = std::accumulate(myVector.begin(), myVector.end(), 0);
	
	// 8. unique -> 중복 요소 제거 (단, 정렬된 벡터여야 함)
	std::unique(myVector.begin(), myVector.end());
	
	return 0;
}