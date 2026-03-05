// 1. 퀵 정렬(sort 함수) - 안정 정렬
// 퀵정렬은 기본적으로 '불안정 정렬'이다.
// 순서의 안정성이 필요하면, [stable_sort]를 사용한다.
// 다만 시간은 sort보다 조금 느리다.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool compare_pairs(const pair<int, string>& a, const pair<int, string>& b) {
	return a.first < b.first;	// 오름차순
}
int main() {
	vector<pair<int, string>> pairs_v = {
		{5,"apple"},		// 같은 값 5
		{2,"orange"},
		{5,"banana"},		// 같은 값 5
		{3,"grape"}
	};

	// 안정 정렬
	stable_sort(pairs_v.begin(), pairs_v.end(), compare_pairs);	// 사용자 지정 함수 형식

	// 출력
	for (int i = 0; i < pairs_v.size(); i++) {
		cout << pairs_v[i].first << " : " << pairs_v[i].second << endl;
	}

	return 0;
}