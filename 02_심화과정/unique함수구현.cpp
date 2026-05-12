// std::unique의 활용
// 중복을 제거하는 함수이다.
// 연속된 중복만을 제거하므로, [정렬]이 우선시되어야한다.
#include <iostream>
#include <vector>
using namespace std;

void MyUniqueFunc(vector<int>& vec) {
	// first : 탐색용, result = 옮겨질 위치,기준값 , last = 벡터의 끝
	auto first = vec.begin(), result = vec.begin(), last = vec.end();
	if (vec.empty())	return;			// 빈 벡터 처리
	while (++first != last) {			// 두 번째 요소부터, 마지막까지 탐색
		if (!(*first == *result)) {		// 탐색값(fist)이 기준값(unique)과 달라지면,
			*(++result) = *first;		// 위치를 옮긴 후, 탐색값으로 덮는다.
		}
	}
	return;
}
void PrintVec(const vector<int> vec) {
	for (auto x : vec) {
		cout << x << " - ";
	}
	cout << '\n';
}

int main() {
	vector<int> parent_vec = { 10, 10, 20, 30, 20, 10, 10 };
	
	vector<int> vec1 = parent_vec;
	cout << "내가 직접 구현한 Unique함수" << '\n';
	PrintVec(vec1);
	MyUniqueFunc(vec1);
	PrintVec(vec1);

	vector<int> vec2 = parent_vec;
	cout << "\nstd::unique함수" << '\n';
	PrintVec(vec2);
	MyUniqueFunc(vec2);
	PrintVec(vec2);

	// 10 20 30 20 10 10 10 으로 나옴!
	// 앞쪽에 유일한 값들을 모으고, 나머지는 뒤로 밀어낸다.
	// 또한 [연속된 중복]만을 제거한다.
	// 예를 들어 {10 - 20 - 10 - 20 -10} 이면, 똑같이 {10 - 20 - 10 - 20 -10}으로 나온다.
	// 그래서 항상 정렬이 먼저 되어야 한다.

	return 0;
}