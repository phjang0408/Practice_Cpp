// 1. 퀵 정렬(sort 함수)
// 평균 O(nlog(n)), 최악 O(n^2)
// 장점 : 속도가 빠르다, 추가 메모리 공간을 필요로 하지 않는다.
// 단점 : 정렬된 리스트에 대해서는, 수행시간이 더 많이 걸린다. (퀵 정렬의 불균형 분할)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <typename T>
void print_all_elements(vector<T> vec) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << '\n';
}

bool icompare(const int& a, const int& b) {
	return a < b ? true : false;	// 사용자 지정 함수를, 오름차순으로 설정
}

int main() {
	// 1. 오름차순 정렬
	vector<int> vec1 = { 7,6,3,5,4,1,2,0,8 };
	sort(vec1.begin(), vec1.end());		// 1. 기본형 (오름차순)
	print_all_elements(vec1);		

	// 2. 내림차순 정렬
	vector<int> vec2 = { 7,6,3,5,4,1,2,0,8 };
	sort(vec2.begin(), vec2.end(), std::greater<int>());	// 2. greater함수 (내림차순)
	print_all_elements(vec2);

	// 3. 사용자 지정 함수
	vector<int> vec3 = { 7,6,3,5,4,1,2,0,8 };
	sort(vec3.begin(), vec3.end(), icompare);	// 2. 사용자 정의 함수 [인자는 함수의 주소!]
	print_all_elements(vec3);

	return 0;
}